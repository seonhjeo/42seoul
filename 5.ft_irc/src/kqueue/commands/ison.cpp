#include "ison.hpp"

Ison::Ison(const Message &input, Server *server): Command(input, server)
{
	execute();
}

Ison::~Ison()
{
}

void Ison::execute()
{
	int fd = this->get_message().get_sender_fd();
	std::map<int, Client*> cl = this->get_server()->get_cl();

	if (cl[fd]->get_authorized()== false)
		cl[fd]->set_buf(this->set_log("451", cl[fd]->get_nickname(), ":You have not registered"));
	else if (this->get_message().get_params().size() != 1)
		cl[fd]->set_buf(this->set_log("461", cl[fd]->get_nickname(), "ISON :Not enough parameters"));
	else if (this->get_message().get_params()[0].size() > CLIENT_NICKNAME_MAX)
		cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":The limited number 9"));
	else
	{
		std::map<int, Client*>::iterator it = cl.begin();
		std::string i_msg = ":*1" + this->get_message().get_params()[0];
		for(; it != cl.end(); it++)
			if (it->second->get_nickname().compare(this->get_message().get_params()[0]) == 0)
				cl[fd]->set_buf(this->set_log("303", cl[fd]->get_nickname(), i_msg));
		if (cl[fd]->get_buf().size() == 0)
			cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":Failed to find."));
	}
	return ;
	
}
