#ifndef MYSERVER_HPP
#define MYSERVER_HPP

#include <algorithm>
#include <sys/poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <vector>
#include <map>
#include <poll.h>
#include <unistd.h>
#include <string>

class myServer
{
private:
	bool	_isRunning;

	std::string	_password;
	std::string _portnum;

	myServer();

public:
	myServer(std::string password, std::string portnum);
	~myServer();

	int		start();
};

#endif
