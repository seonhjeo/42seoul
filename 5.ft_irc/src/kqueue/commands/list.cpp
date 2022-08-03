#include "list.hpp"

List::List(const Message &input, Server *server): Command(input, server)
{
	execute();
}

List::~List()
{
}

void List::execute()
{
	int fd = this->get_message().get_sender_fd();
	std::map<int, Client*> cl = this->get_server()->get_cl();

	if (this->get_message().get_command().compare("LIST") != 0)
		cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":error at executing LIST commands"));
	else if (this->get_message().get_params().size() != 0)
		cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":invalid members, right form is LIST"));
	else if (cl[fd]->get_authorized()== false)
		cl[fd]->set_buf(this->set_log("451", cl[fd]->get_nickname(), ":You have not registered"));
	else if (this->get_server()->get_ch().size() == 0)
		cl[fd]->set_buf(this->set_log("999", cl[fd]->get_nickname(), ":No channel list found."));
	else
	{
		std::string msg;
		std::map<std::string, Channel*>::const_iterator it = this->get_server()->get_ch().begin();
		std::map<std::string, Channel*>::const_iterator ite = this->get_server()->get_ch().end();
		size_t i = 0;
		while (it != ite)
		{
			msg = (*it).first + " * " + ":no topic";
			cl[fd]->set_buf(this->set_log("322", cl[fd]->get_nickname(), msg));
			it++;
			i++;
			msg.clear();
			if (i == this->get_server()->get_ch().size())
				cl[fd]->set_buf(this->set_log("323", cl[fd]->get_nickname(), ":END of LIST"));
		}	
	}
	return ;
}
