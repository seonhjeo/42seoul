#include "pong.hpp"

Pong::Pong(const Message &input, Server *server): Command(input, server)
{
	execute();
}

Pong::~Pong()
{
}

void Pong::execute()
{
	int fd = this->get_message().get_sender_fd();
	std::map<int, Client*> cl = this->get_server()->get_cl();
	std::string str = SERVER_NAME;

	if (cl[fd]->get_authorized()== false)
		cl[fd]->set_buf(this->set_log("451", cl[fd]->get_nickname(), ":You have not registered"));
	else if (this->get_message().get_params().size() != 1)
		cl[fd]->set_buf(this->set_log("461", cl[fd]->get_nickname(), "PONG :Not enough parameters"));
	else if (this->get_message().get_params()[0].compare(str) != 0)
		cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":It's different from the pong data."));
	else if (cl[fd]->get_check_time() == 2 && cl[fd]->get_time() > 0)
	{
		cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), ":Your connection has been verified."));
		time_t new_time = time(NULL);
		cl[fd]->set_time(new_time);
		cl[fd]->set_check_time(1);	
	}
	return ;
}
