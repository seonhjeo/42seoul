#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "../server.hpp"
# include "../command.hpp"

class Privmsg : public Command
{
private:
    Privmsg();
    Privmsg(const Privmsg &other);
	Privmsg &operator=(const Privmsg &other);
public:
    Privmsg(const Message &input, Server *server);
    virtual ~Privmsg();
    virtual void execute();
};

#endif
