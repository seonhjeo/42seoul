#ifndef PONG_HPP
# define PONG_HPP

# include "../server.hpp"
# include "../command.hpp"

class Pong : public Command
{
private:
    Pong();
    Pong(const Pong &other);
	Pong &operator=(const Pong &other);
public:
    Pong(const Message &input, Server *server);
    virtual ~Pong();

    virtual void execute();
};

#endif
