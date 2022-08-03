#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "message.hpp"
#include "client.hpp"
#include "config.hpp"

class Server;

class Command
{
private:
    Message _input;
    Server* _server;

    Command();
    Command(const Command &other);
    Command &operator=(const Command &other);

public:
    Command(const Message &input, Server *server);

    virtual ~Command();

    std::string set_log(std::string num, std::string nick, std::string log);
    std::string set_privte_log(std::string nick, std::string num, std::string target, std::string log);

    const Server*   get_server(void);
    Server*         access_server(void);
    const Message   &get_message(void) const;

    virtual void    execute() = 0;
};

#endif
