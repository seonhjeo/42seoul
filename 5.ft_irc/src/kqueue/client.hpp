#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <sys/time.h>
# include <vector>

# include "config.hpp"

class Client
{
private:
    int             _fd;
    std::string     _nickname;
    std::string     _username;
    std::string     _realname;
	bool			_is_authorized;
	//시간 체크해야하는 것을 채크하기 위해 넣어 보았음
	int				_time_check;
	bool			_is_quit;
	//시간 분 초 등으로 나눌필요는 없어서 숫자로 받기 위해서
	time_t			_time;
	std::vector<std::string>	_buf;

	Client();
	Client(const Client &other);
	Client &operator=(const Client &other);

public:
	Client(int &fd);
	~Client();

	void	set_nickname(std::string &nickname);
	void	set_username(std::string &username);
	void	set_realname(std::string &realname);
	void	set_authorized(bool auth);
	void	set_check_time(int auth);
	void	set_is_quit(bool auth);
	//time_t로 변경으로 인해 변경
	void	set_time(time_t &time);
	void	set_buf(std::string	buf);

	int					get_fd() const;
	const std::string	get_nickname() const;
	const std::string	get_username() const;
	const std::string	get_realname() const;
	bool				get_authorized() const;
	int					get_check_time() const;
	bool				get_is_quit() const;
	
	//time_t로 바꾸니 const 앞에 못 붙여서 지움
	time_t						get_time(void) const;
	std::vector<std::string>	&get_buf(void);
	void						clear_buf(void);

	std::string					getUserPerfix() const;
};

#endif
