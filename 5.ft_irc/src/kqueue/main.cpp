#include "server.hpp"

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 3)
			throw std::runtime_error("Number of parameters is not correct");
		Server center(argv[1], argv[2]);
		center.init_server();
		center.start_server();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
