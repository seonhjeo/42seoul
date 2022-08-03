#ifndef ALLCONTENT_HPP
# define ALLCONTENT_HPP

# define BUF_SIZE	4096
# define FD_MAX		OPEN_MAX

# include <iostream>
# include <string>
# include <vector>
# include <new>

# include <unistd.h>

# include <sys/socket.h>
# include <sys/select.h>
# include <sys/resource.h>
# include <sys/types.h>

# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

enum socketType
{
	FD_FREE, FD_SERVER, FD_CLIENT
};


#endif