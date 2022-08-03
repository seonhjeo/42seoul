#ifndef JOIN_HPP
# define JOIN_HPP

# include "../server.hpp"
# include "../command.hpp"

class Join : public Command
{
private:
    Join();
    Join(const Join &other);
	Join &operator=(const Join &other);
public:
    Join(const Message &input, Server *server);
    virtual ~Join();

    bool    check_word(std::string param);
	virtual void	execute();
};

#endif
