#ifndef PING_HPP
# define PING_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Server;

class Ping : public Command
{
private:
    Ping();
    Ping(const Ping &other);
	Ping &operator=(const Ping &other);
public:
    Ping(const Message &input, Server *server);
    virtual ~Ping();

    virtual void execute();
};

#endif
