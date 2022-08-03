#include "part.hpp"

Part::Part(const Message &input, Server *server): Command(input, server)
{
	this->execute();
}

Part::~Part()
{
}

void Part::execute()
{
	int fd = this->get_message().get_sender_fd();
	std::map<int, Client*> cl = this->get_server()->get_cl();
	std::map<std::string, Channel*> channels = this->get_server()->get_ch();


	if (cl[fd]->get_authorized()== false)
		cl[fd]->set_buf(this->set_log("451", cl[fd]->get_nickname(), ":You have not registered"));
	else if (this->get_message().get_params().size() != 1)
		cl[fd]->set_buf(this->set_log("461", cl[fd]->get_nickname(), "PART :Not enough parameters"));
	else if (channels.find(this->get_message().get_params()[0]) == channels.end())
		cl[fd]->set_buf(this->set_log("403", cl[fd]->get_nickname(), this->get_message().get_params()[0] + " :No such channel"));
	else
	{
		std::string msg_ch = this->get_message().get_params()[0];
		std::vector<int> ch_cl = channels[msg_ch]->get_clients();

		Channel *targetch = channels.find(msg_ch)->second;
		if (targetch->is_in_client(fd) == false)
			cl[fd]->set_buf(this->set_log("442", cl[fd]->get_nickname(), msg_ch + " :You're not on that channel"));
		else if (ch_cl.size() == 0)
			cl[fd]->set_buf(this->set_log("403", cl[fd]->get_nickname(), msg_ch + " :No such channel"));
		else if (channels[msg_ch]->is_in_client(fd) == true)
		{
			if (ch_cl.size() > 1)
			{
				if (channels[msg_ch]->get_oper() == fd)
				{
					int n_fd = channels[msg_ch]->next_fd(fd);
                    if (n_fd != -1)
						channels[msg_ch]->change_oper(n_fd);
				}
				channels[msg_ch]->delete_client(fd);
				std::string log = "User left " + msg_ch;
				cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), log));
			}
			else if (ch_cl.size() == 1 && channels[msg_ch]->get_oper() == fd)
			{
				channels[msg_ch]->delete_client(fd);
				this->access_server()->channel_close(msg_ch);
				std::string log = msg_ch + " exploded";
				cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), log));
			}
		}
		else if (channels[msg_ch]->is_in_client(fd) == false)
			cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), "exist"));
	}
	return ;
}
