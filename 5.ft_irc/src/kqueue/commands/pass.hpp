#ifndef PASS_HPP
# define PASS_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Pass : public Command
{
private:
    Pass();
    Pass(const Pass &other);
	Pass &operator=(const Pass &other);
public:
    Pass(const Message &input, Server *server);
    virtual ~Pass();

    virtual void execute();
};

#endif
