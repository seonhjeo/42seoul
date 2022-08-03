#include "server.hpp"

//생성자 매개변수 포트, 비번
Server::Server(const std::string& port, const std::string& pw)
	: _port(port), _pw(pw), _ping_client_check(false)
{
	this->_cl.clear();
	this->_ch.clear();
	this->_changelist.clear();
	bzero(this->_buf, sizeof(this->_buf));
}

Server::~Server()
{
	std::cout << "\n";
	while (_cl.empty() == false)
	{
		client_type::iterator	cl_it = _cl.begin();
		client_close((*cl_it).first);
	}
	while (_ch.empty() == false)
	{
		channel_type::iterator	ch_it = _ch.begin();
		channel_close((*ch_it).first);
	}
	this->_cl.clear();
	this->_ch.clear();
	this->_changelist.clear();
	close(_fd);
	std::cout << "Server quit!" << std::endl;
}

void	Server::init_server(void)
{
	create_socket();
	set_socket_option();
	listen_socket();
}

// Socket 생성
void	Server::create_socket(void)
{
	this->_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_fd < 0)
		throw std::runtime_error("Socket creation Failed");
	std::cout << "Socket connect Success!" << std::endl;
}

// Socket 옵션 세팅, Bind
void	Server::set_socket_option(void)
{
	struct sockaddr_in _addrs;
	int result = 1;

	// Socket 옵션 초기화
	if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR, &result, sizeof(result)))
		throw std::runtime_error("Setsockopt setting Failed");
	std::cout << "Socket setting Success!" << std::endl;

	// Non Block 옵션 설정
	if (fcntl(this->_fd, F_SETFL, O_NONBLOCK) == -1)
		throw std::runtime_error("Server Fcntl NonBlock setting Failed");
	std::cout << "Socket  NonBlock setting Success!" << std::endl;

	// Socket 옵션 설정
	bzero(&_addrs, sizeof(struct sockaddr_in));
	_addrs.sin_family = AF_INET;
	_addrs.sin_addr.s_addr = INADDR_ANY;
	_addrs.sin_port = htons(std::stoi(_port));

	// Socket bind
	if (::bind(this->_fd, (struct sockaddr *)&_addrs, sizeof(_addrs)) < 0)
		throw std::runtime_error("Bind setting Failed");
	std::cout << "Bind setting Success!" << std::endl;
}

// Socket Listen
void	Server::listen_socket(void)
{
	if (listen(this->_fd, BACKLOG) < 0)
		throw std::runtime_error("listen standby Failed");
	std::cout << "listen setting Success!" << std::endl;
}

//클라이언트 close 부분
void	Server::client_close(int cl_fd)
{
	std::cerr << "Client socket Failed\n" << "Client socket: " << cl_fd << std::endl;
    close(cl_fd);
	delete (_cl[cl_fd]);
    _cl.erase(cl_fd);
}

void	Server::channel_close(std::string ch)
{
	delete(_ch[ch]);
	_ch.erase(ch);
}

//EV_SET 초기화 부분
void	Server::change_events(std::vector<struct kevent>& list, int ident, int check)
{
	struct kevent tmp;
	
	if (check == READ)
		EV_SET(&tmp, ident, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	else if (check == WRITE)
		EV_SET(&tmp, ident, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
	else if (check == SIGNAL)
	{
		EV_SET(&tmp, ident, EVFILT_SIGNAL, EV_ADD | EV_ENABLE, 0, 0, NULL);
		signal(ident, SIG_IGN);
	}
	list.push_back(tmp);
}


// kqueue 생성, Server 소켓 옵션 변경
int		Server::create_kqueue(void)
{
	int kq_fd = kqueue();
	if (kq_fd == -1)
		throw std::runtime_error("Kqueue Failed");
	
	change_events(this->_changelist, this->_fd, READ);
	change_events(this->_changelist, SIGINT, SIGNAL);
	std::cout << "Server Started" << std::endl;
	return (kq_fd);
}

//클라이언트 소켓인 서버 소켓이랑 같으면 안되고 클라이언트가 종료 되었을때 띄어주는 client_close
void	Server::error_flag(const int& cl_fd)
{
	if (static_cast<int>(cl_fd) == _fd)
		throw std::runtime_error("Server socket Failed");
	else
		client_close(cl_fd);
}

// 서버에서 클라이언트를 accept
void	Server::accept_client_for_server(void)
{
	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	int cl_fd = accept(this->_fd, (sockaddr *)&addr, &len);
	
	if (cl_fd == -1)
		throw std::runtime_error("Server Accept Creation failed");
	std::cout << "new client : " << cl_fd << std::endl;

	fcntl(cl_fd, F_SETFL, O_NONBLOCK);
	change_events(this->_changelist, cl_fd, READ);
	change_events(this->_changelist, cl_fd, WRITE);

	Client *client = new Client(cl_fd);
	_cl.insert(std::make_pair(cl_fd, client));
}
// 개별 명령어 실행 함수
void	Server::individual_command(std::string buf, int ident, bool check)
{
	if (check == true)
		this->_ping_client_check = check;
	Message tempmsg(ident, buf);
	this->cmd_execute(tempmsg, ident);
}

//pong 시간 체크기능
void	Server::pong_client_timecheck(int ident)
{
	time_t check_time = this->_cl[ident]->get_time();
	if (check_time + PONGTIMES <= time(NULL))
		individual_command("QUIT\n", ident, false);
}

//ping 시간 체크기능
void	Server::ping_client_timecheck(int check, int ident)
{
	if (this->_cl.size() > 0)
	{
		client_type::iterator it = _cl.begin();
		time_t new_time = time(NULL);
		for (; it != _cl.end(); it++)
		{
			if ((*it).second->get_check_time() == 2)
			{
				pong_client_timecheck((*it).first);
				continue ;
			}
			if (check == 1 && ident != -1 && (*it).second->get_time() == 0)
			{
				individual_command("PING JBS\n", ident, true);
				break ;
			}
			else if (check == 2 && (*it).second->get_time() != 0 && (*it).second->get_time() + PINGTIMES <= new_time)
			{
				individual_command("PING JBS\n", (*it).first, true);
				break ;
			}
		}
	}
}

// 클라이언트에서 event받아서 써줌
void	Server::receive_data_from_client(int ident)
{
	int	read_fd = read(ident, this->_buf, sizeof(this->_buf));		

	if (read_fd <= 0)
	{
		if (read_fd < 0)
			std::cerr << "Client read Failed\n";
		memset(this->_buf, 0, sizeof(this->_buf));
		individual_command("QUIT\n", ident, false);
	}
	else
	{
		std::string temp(this->_buf);
		if (this->_buf[read_fd - 1] == '\n')
			this->_buf[read_fd - 1] = '\0';
		std::cout << "received data from " << ident << " : " << this->_buf << std::endl;
		Message tempmsg(ident, temp);
		cmd_execute(tempmsg, ident);
	}
	memset(this->_buf, 0, sizeof(this->_buf));
}

//클라이언트 쓰는 부분
void	Server::write_clients(int ident)
{
	if (_cl[ident]->get_buf().size() != 0)
	{
		for (size_t i = 0; i < _cl[ident]->get_buf().size(); ++i)
			write(ident, _cl[ident]->get_buf()[i].c_str(), _cl[ident]->get_buf()[i].length());
		_cl[ident]->clear_buf();
		if (_cl[ident]->get_is_quit() == true && _cl[ident]->get_authorized() == false)
			client_close(ident);
	}
}

bool	Server::exit_server(void)
{
	std::map<int, Client*>::iterator	it = _cl.begin();
	std::string	log;
	for (; it != _cl.end(); ++it)
	{
		log = ":" + std::string(SERVER_NAME) + " 999 ";
		log += (*it).second->get_nickname() + ":The connection to the server has been lost.\r\n";
		write((*it).first, log.c_str(), log.length());
	}
	return (false);
}

// 이벤트 발생시 처리해주는 부분
bool	Server::handle_events(int event_fd)
{
	int	ident = 0;

	for(int i = 0; i < event_fd; ++i)
	{
		ident = static_cast<int>(_eventlist[i].ident);
		if (_eventlist[i].flags & EV_ERROR)
			error_flag(ident);
		else if (_eventlist[i].filter == EVFILT_READ)
		{
			if (ident == _fd)
				accept_client_for_server();
			else if(_cl.find(ident) != _cl.end())
				receive_data_from_client(ident);
		}
		else if (_eventlist[i].filter == EVFILT_WRITE)
			write_clients(ident);
		else if (_eventlist[i].filter == EVFILT_SIGNAL)
			return (exit_server());
	}
	return (true);
}

//kqueue 선언 부분
bool	Server::start_server(void)
{
	int event_fd = 0, kq_fd = create_kqueue();
	while (RUN)
	{
		event_fd = kevent(kq_fd, &_changelist[0], _changelist.size(), _eventlist, 8, NULL);
		if (event_fd == -1)
			throw std::runtime_error("Kevent Failed");
		_changelist.clear();
		ping_client_timecheck(2, -1);
		if (handle_events(event_fd) == false)
			return (false);
	}
	return (true);
}

// 채널 내의 모든 클라이언트의 출력 버퍼 설정
void	Server::set_buf_of_cl_in_ch(std::string ch_name, std::string buf, int authfd)
{
	Channel *ch = this->_ch.find(ch_name)->second;

	std::vector<int> cl_temp = ch->get_clients();
	std::vector<int>::iterator it_cl = cl_temp.begin();
	//while로 돌리니 sagment error 떠서 for문으로 바꿔보니 안나서 일단 변경
	for (; it_cl != cl_temp.end(); it_cl++)
	{
		if (*it_cl != authfd)
			this->_cl.find(*it_cl)->second->set_buf(buf);
	}
}

// 클라이언트 닉네임을 입력하면 해당 클라이언트의 fd를 반환하는 함수
int		Server::get_cl_fd_by_nick(std::string cl_nick) const
{
	client_type::const_iterator it = this->_cl.begin();
	while (it != this->_cl.end())
	{
		if (it->second->get_nickname() == cl_nick)
			return(it->second->get_fd());
		it++;
	}
	return (ERROR);
}

void	Server::add_channel(std::string name, std::string password, int oper)
{
	Channel*	new_channel = new Channel(name, password, oper);
	_ch.insert(std::make_pair(name, new_channel));
}

void	Server::cmd_execute(Message &message, int ident)
{
	std::string cmd = message.get_command();
	if (cmd.compare("PASS") == 0)
		Pass pass(message, this);
	else if (cmd.compare("NICK") == 0)
	{
		Nick nick(message, this);
		if (_cl[ident]->get_check_time() == 1)
			ping_client_timecheck(1, ident);
	}
	else if (cmd.compare("USER") == 0)
		User user(message, this);
	else if (cmd.compare("HELP") == 0)
		Help help(message, this);
	else if (this->_ping_client_check == true && cmd.compare("PING") == 0)
	{
		Ping s_ping(message, this);
		this->_ping_client_check = false;
	}
	else if (cmd.compare("JOIN") == 0)
		Join join(message, this);
	else if (cmd.compare("PRIVMSG") == 0)
		Privmsg privmsg(message, this);
	else if (cmd.compare("LIST") == 0)
		List s_list(message, this);
	else if (cmd.compare("PART") == 0)
		Part s_part(message, this);
	else if (cmd.compare("KICK") == 0)
		Kick kick(message, this);
	else if (cmd.compare("PONG") == 0)
		Pong s_pong(message, this);
	else if (cmd.compare("ISON") == 0)
		Ison s_ison(message, this);
	else if (cmd.compare("QUIT") == 0)
		Quit s_quit(message, this);	
}
