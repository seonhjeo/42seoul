#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <vector>
# include <string>
# include <algorithm>
# include "config.hpp"

class Channel
{
private:
    std::vector<int>    _clients;
    const std::string   _name;
    const std::string   _password;
    int                 _oper;

    Channel();
public:
    Channel(std::string name, std::string password, int oper);
    ~Channel();

    std::vector<int>    get_clients(void) const;
    std::string         get_name(void) const;
    std::string         get_password(void) const;
    int                 get_oper(void) const;
    void    set_oper(int oper);

    int     next_fd(int fd);
    int     change_oper(int fd);
    int     add_client(int fd);
    int     delete_client(int fd);
    bool    is_in_client(int fd);
};

#endif
