#include "client.hpp"

Client::Client() {};

Client::Client(int &fd) : _fd(fd)
{
    this->_is_authorized = false;
    this->_time_check = 0;
    this->_is_quit = false;
    this->_time = NULL;
    this->_nickname = "";
    this->_realname = "";
    this->_username = "";
    this->clear_buf();
};

Client::~Client() {};

void	Client::set_nickname(std::string &nickname)
{
    this->_nickname = nickname;
}

void	Client::set_username(std::string &username)
{
    this->_username = username;
}

void	Client::set_realname(std::string &realname)
{
    this->_realname = realname;
}

void	Client::set_buf(std::string buf)
{
    this->_buf.push_back(buf);
}

void	Client::set_authorized(bool auth)
{
    this->_is_authorized = auth;
}

void    Client::set_check_time(int auth)
{
    this->_time_check = auth;
}

void	Client::set_is_quit(bool auth)
{
    this->_is_quit = auth;
}

void	Client::set_time(time_t &time)
{
	_time = time;
}

int Client::get_fd() const
{
    return (this->_fd);
}

const std::string   Client::get_nickname() const
{
    return (this->_nickname);
}

const std::string   Client::get_username() const
{
    return (this->_username);
}

const std::string   Client::get_realname() const
{
    return (this->_realname);
}

bool    Client::get_authorized() const
{
    return (this->_is_authorized);
}

int     Client::get_check_time() const
{
    return (this->_time_check);
}

bool    Client::get_is_quit() const
{
    return (this->_is_quit);
}


std::vector<std::string>	&Client::get_buf(void)
{
	return (this->_buf);
}

time_t  Client::get_time(void) const
{
	return (this->_time);
}

void    Client::clear_buf(void)
{
    this->_buf.clear();
}

std::string		Client::getUserPerfix() const
{
    return (":" + this->_nickname + "!" + this->_username + "@" + std::string(SERVER_DOMAIN) + " ");
};
