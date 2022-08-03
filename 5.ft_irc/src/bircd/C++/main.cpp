#include "Server.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: bad argument" << std::endl;
		return (1);
	}
	else
	{
		Server	serv(argv[1]);
		serv.creat();
		while (42)
		{
			serv.init_fd();
			serv.do_select();
			serv.check_fd();
		}
	}
	return (0);
}