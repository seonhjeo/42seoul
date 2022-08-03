#ifndef SOCKET_HPP
# define SOCKET_HPP

#include "./AllContent.hpp"

class Socket
{
private:
	int		_type;
	char	_bufWrite[BUF_SIZE + 1];
	char	_bufRead[BUF_SIZE + 1];
public:
	Socket();
	~Socket();

	void	initSocket();
	int		getType(void) const;
	char	*getBufRead(void);
	char	*getBufWrite(void);
	void	setType(int type);

	int	getBufWriteLength();
	int	getBufReadLength();

	void	doRead(Socket* fds, int socketFd);
	void	doWrite(Socket* fds, int socketFd);
	void	sAccept(Socket* fds, int socketFd);
	void	cRead(Socket* fds, int socketFd);
	void	cWrite(Socket* fds, int socketFd);
};

Socket::Socket()
{ initSocket(); }

Socket::~Socket()
{}

void	Socket::initSocket(void)
{
	_type = FD_FREE;
	_bufWrite[0] = '\0';
	_bufRead[0] = '\0';
}

int		Socket::getType(void) const
{ return (_type); }


char	*Socket::getBufRead(void)
{ return (_bufRead); }

char	*Socket::getBufWrite(void)
{ return (_bufWrite); }

void	Socket::setType(int type)
{ _type = type; }

int	Socket::getBufWriteLength(void)
{ return (strlen(_bufWrite)); }

int	Socket::getBufReadLength(void)
{ return (strlen(_bufRead)); }

void	Socket::doRead(Socket* fds, int socketFd)
{
	if (fds[socketFd].getType() == FD_SERVER)
		this->sAccept(fds, socketFd);
	else if (fds[socketFd].getType() == FD_CLIENT)
		this->cRead(fds, socketFd);
}

void	Socket::doWrite(Socket* fds, int socketFd)
{
	if (fds[socketFd].getType() == FD_CLIENT)
		this->cWrite(fds, socketFd);
}

void	Socket::sAccept(Socket* fds, int socketFd)
{
	struct sockaddr_in	csin;
	socklen_t			csin_len = sizeof(csin);
	int					cs = accept(socketFd, (struct sockaddr*)&csin, &csin_len);

	std::cout << "New Client #" << cs << " from " << inet_ntoa(csin.sin_addr)
				<< ":" << ntohs(csin.sin_port) << std::endl;
	fds[cs].setType(FD_CLIENT);
}

void	Socket::cRead(Socket* fds, int socketFd)
{
	int	r = recv(socketFd, fds[socketFd].getBufRead(), BUF_SIZE, 0);
	if (r <= 0)
	{
		close(socketFd);
		fds[socketFd].initSocket();
		std::cout << "Client #" << socketFd << "gone away" << std::endl;
	}
	else
	{
		for (int i = 0; i < FD_MAX; ++i)
		{
			if (fds[i].getType() == FD_CLIENT && i != socketFd)
				send(i, fds[socketFd].getBufRead(), r, 0);
		}
	}
}

void	Socket::cWrite(Socket* fds, int socketFd)
{
	(void)fds;
	(void)socketFd;
}

#endif