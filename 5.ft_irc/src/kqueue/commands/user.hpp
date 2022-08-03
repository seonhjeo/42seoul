#ifndef USER_HPP
# define USER_HPP

# include "../server.hpp"
# include "../command.hpp"
# include "../config.hpp"

class User : public Command
{
private:    
    User();
    User(const User &other);
	User &operator=(const User &other);
public:
    User(const Message &input, Server *server);
    virtual ~User();

    virtual void execute();
};

#endif
