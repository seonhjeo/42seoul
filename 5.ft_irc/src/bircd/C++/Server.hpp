#ifndef SERVER_HPP
# define SERVER_HPP

# include "./Socket.hpp"

class Socket;

class Server
{
private:
	Socket	*_fds;
	int	_port;
	int	_max;
	int	_r;
	fd_set	_fd_read;
	fd_set	_fd_write;
public:
	Server(char *port);
	~Server();

	void	creat();
	void	init_fd();
	void	do_select();
	void	check_fd();
};

Server::Server(char *port)
	: _fds(new Socket[FD_MAX]), _port(atoi(port)), _max(0), _r(0)
{
	for (int i = 0; i < FD_MAX; ++i)
		_fds[i].initSocket();
}

Server::~Server()
{
	delete[] _fds;
}

void	Server::creat(void)
{
	int	s;
	struct sockaddr_in	sin;
	struct protoent *pe;

	pe = ((struct protoent*)getprotobyname("tcp"));
	s = socket(PF_INET, SOCK_STREAM, pe->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(_port);
	bind(s, (struct sockaddr*)&sin, sizeof(sin));
	listen(s, 42);
	_fds[s].setType(FD_SERVER);
}

void	Server::init_fd(void)
{
	int	i = -1;
	
	this->_max = 0;
	FD_ZERO(&_fd_read);
	FD_ZERO(&_fd_write);
	while (++i < FD_MAX)
	{
		if (_fds[i].getType() != FD_FREE)
		{
			FD_SET(i, &_fd_read);
			if (_fds[i].getBufWriteLength() > 0)
				FD_SET(i, &_fd_write);
			_max = std::max(_max, i);
		}
	}
}

void	Server::do_select(void)
{ _r = select(_max + 1, &_fd_read, &_fd_write, NULL, NULL); }

void	Server::check_fd(void)
{
	int	i = -1;

	while ((++i < FD_MAX) && _r > 0)
	{
		if (FD_ISSET(i, &_fd_read))
			_fds[i].doRead(_fds, i);
		if (FD_ISSET(i, &_fd_write))
			_fds[i].doWrite(_fds, i);
		if (FD_ISSET(i, &_fd_read) || FD_ISSET(i, &_fd_write))
			--_r;
	}
}

#endif