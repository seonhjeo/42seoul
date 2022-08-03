#include "ping.hpp"

Ping::Ping(const Message &input, Server *server): Command(input, server)
{
	execute();
}

Ping::~Ping()
{
}

void Ping::execute()
{
	int fd = this->get_message().get_sender_fd();
	std::map<int, Client*> cl = this->get_server()->get_cl();

	if (this->get_message().get_params().size() != 1)
		cl[fd]->set_buf(this->set_log("461", cl[fd]->get_nickname(), "PING :Not enough parameters"));
	else
	{ 	
		std::string str(":" + this->get_message().get_command() + " " + this->get_message().get_params()[0]);
		cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), str));
		cl[fd]->set_check_time(2);
		time_t new_time = time(NULL);
		cl[fd]->set_time(new_time);
	}
	return ;
}
