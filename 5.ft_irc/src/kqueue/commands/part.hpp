#ifndef PART_HPP
# define PART_HPP

# include "../server.hpp"
# include "../command.hpp"

class Part : public Command
{
private:
    Part();
    Part(const Part &other);
	Part &operator=(const Part &other);
public:
    Part(const Message &input, Server *server);
    virtual ~Part();
    virtual void execute();
};

#endif
