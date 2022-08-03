#ifndef LIST_HPP
# define LIST_HPP

# include "../server.hpp"
# include "../command.hpp"

class List : public Command
{
private:
    List();
    List(const List &other);
	List &operator=(const List &other);

public:
    List(const Message &input, Server *server);
    virtual ~List();

    virtual void execute();
};

#endif
