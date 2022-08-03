#include "channel.hpp"

Channel::Channel(std::string name, std::string password, int oper)
    : _name(name), _password(password), _oper(oper)
{
    _clients = std::vector<int>();
    _clients.clear();
}

Channel::~Channel()
{
    _clients.clear();
}

std::vector<int>    Channel::get_clients(void) const
{ return (_clients); }

std::string         Channel::get_name(void) const
{ return (_name); }

std::string         Channel::get_password(void) const
{ return (_password); }

int                 Channel::get_oper(void) const
{ return (_oper); }

void    Channel::set_oper(int oper)
{ _oper = oper; }

int     Channel::next_fd(int fd)
{
    std::vector<int>::iterator it = _clients.begin();
    while (it != _clients.end())
    {
        if (*it == fd)
        {
            ++it;
            return (*it);
        }
        it++;
    }
    return (ERROR);
}

int     Channel::change_oper(int fd)
{
    if (fd != get_oper())
        set_oper(fd);
    else
        return (ERROR);
    return (SUCCESS);
}

int     Channel::add_client(int fd)
{
    if (is_in_client(fd) == false)
        _clients.push_back(fd);
    else
        return (ERROR);
    return (SUCCESS);
};

int     Channel::delete_client(int fd)
{
    std::vector<int>::iterator  find_fd_iter = std::find(_clients.begin(), _clients.end(), fd);
    if (find_fd_iter != _clients.end())
        _clients.erase(find_fd_iter);
    else
        return (ERROR);
    return (SUCCESS);
}

bool    Channel::is_in_client(int fd)
{
    if (_clients.size() == 0)
        return (false);
    std::vector<int>::iterator  it = _clients.begin();
    for (; it != _clients.end(); ++it)
    {
        if (*it == fd)
            return (true);
    }
    return (false);
}
