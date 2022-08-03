#ifndef NICK_HPP
# define NICK_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class Nick : public Command
{
private:
    Nick();
    Nick(const Nick &other);
	Nick &operator=(const Nick &other);
public:
    Nick(const Message &input, Server *server);
    virtual ~Nick();

    virtual void execute();
};

#endif
