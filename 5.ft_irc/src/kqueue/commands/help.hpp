#ifndef HELP_HPP
# define HELP_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Help : public Command
{
private:
    Help();
    Help(const Help &other);
	Help &operator=(const Help &other);
public:
    Help(const Message &input, Server *server);
    virtual ~Help();

    virtual void execute();
};

#endif
