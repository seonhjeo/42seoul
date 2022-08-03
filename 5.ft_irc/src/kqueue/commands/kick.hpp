#ifndef KICK_HPP
# define KICK_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Kick : public Command
{
private:
    Kick();
    Kick(const Kick &other);
	Kick &operator=(const Kick &other);
public:
    Kick(const Message &input, Server *server);
    virtual ~Kick();

    virtual void execute();
};


#endif
