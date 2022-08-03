#ifndef ISON_HPP
# define ISON_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Server;

class Ison : public Command
{
private:
    Ison();
    Ison(const Ison &other);
	Ison &operator=(const Ison &other);
public:
    Ison(const Message &input, Server *server);
    virtual ~Ison();

    virtual void execute();
};

#endif
