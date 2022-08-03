#include "myserver.hpp"

myServer::myServer(std::string password, std::string portnum)
{
	_isRunning = false;
	_password = password;
	_portnum = portnum;
}
