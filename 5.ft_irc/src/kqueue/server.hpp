#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <sys/socket.h>
# include <sys/types.h>
# include <sys/event.h>
# include <sys/time.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <unistd.h>
# include <vector>
# include <map>

# include "client.hpp"
# include "config.hpp"
# include "channel.hpp"
# include "command.hpp"
# include "message.hpp"

# include "commands/pass.hpp"
# include "commands/nick.hpp"
# include "commands/user.hpp"
# include "commands/help.hpp"
# include "commands/quit.hpp"
# include "commands/ison.hpp"
# include "commands/ping.hpp"
# include "commands/pong.hpp"
# include "commands/join.hpp"
# include "commands/list.hpp"
# include "commands/part.hpp"
# include "commands/privmsg.hpp"
# include "commands/kick.hpp"

class Server
{
private:
	typedef std::map<int, Client*>				client_type;
	typedef std::map<std::string, Channel*>		channel_type;

	int					_fd;
	const std::string	_port;
	const std::string	_pw;
	char				_buf[510];
	bool				_ping_client_check;
	
	client_type			_cl;
	channel_type		_ch;
	
	std::vector<struct kevent>	_changelist;
	struct kevent				_eventlist[8];

	Server();
	void	create_socket(void);
	void	set_socket_option(void);
	void	listen_socket(void);

	void	change_events(std::vector<struct kevent>&, int, int);
	int		create_kqueue(void);
	void	error_flag(const int&);
	void	accept_client_for_server(void);
	void	receive_data_from_client(int ident);

	void	individual_command(std::string buf, int ident, bool check);
	void	ping_client_timecheck(int check, int ident);
	void	pong_client_timecheck(int ident);
	void	write_clients(int);
	bool	exit_server(void);
	bool	handle_events(int event_fd);
	
public:
	Server(const std::string&, const std::string&);
	~Server();

	void	init_server(void);
	bool	start_server(void);

	void	client_close(int);
	void	channel_close(std::string ch);
	
	void	set_buf_of_cl_in_ch(std::string ch_name, std::string buf, int authfd);
	int		get_cl_fd_by_nick(std::string cl_nick) const;
	void	add_channel(std::string name, std::string password, int oper);

	void	cmd_execute(Message &message, int ident);

	
	const std::string	get_pw() const { return (this->_pw); };
	const client_type&	get_cl() const { return (this->_cl); };
	const channel_type&	get_ch() const { return (this->_ch); };
};

#endif
