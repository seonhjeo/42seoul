#ifndef QUIT_HPP
# define QUIT_HPP

# include "../server.hpp"
# include "../command.hpp"

class Server;

class Quit : public Command
{
private:
    Quit();
    Quit(const Quit &other);
	Quit &operator=(const Quit &other);
public:
    Quit(const Message &input, Server *server);
    virtual ~Quit();

    virtual void execute();
};

#endif
