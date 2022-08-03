#include "privmsg.hpp"

Privmsg::Privmsg(const Message &input, Server *server): Command(input, server)
{
	execute();
}

Privmsg::~Privmsg()
{
}

void Privmsg::execute()
{
	int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();

	if (targetcl->get_authorized() == false)
    {
        targetcl->set_buf(this->set_log("451", targetcl->get_nickname(), ":You have not registered"));
        return ;
    }

	if (temp_param.size() == 0)
	{
        targetcl->set_buf(this->set_log("411", targetcl->get_nickname(), ":No recipient given (PRIVMSG)"));
        return ;
    }
	if (temp_param.size() == 1)
	{
		targetcl->set_buf(this->set_log("412", targetcl->get_nickname(), ":No text to send"));
        return ;
	}
	if (temp_param[0][0] == '&' || temp_param[0][0] == '#' || temp_param[0][0] == '+' || temp_param[0][0] == '!')
	{
		std::map<std::string, Channel*> g_ch = this->get_server()->get_ch();
		if (g_ch.find(temp_param[0]) == g_ch.end())
		{
			targetcl->set_buf(this->set_log("401", targetcl->get_nickname(), temp_param[0] + " :No such nick/channel"));
			return ;
		}
		std::string sendch = g_ch.find(temp_param[0])->first;
		if (sendch.empty() == true)
			targetcl->set_buf(this->set_log("401", targetcl->get_nickname(), temp_param[0] + " :No such nick/channel"));
		else if (g_ch.find(temp_param[0])->second->is_in_client(authfd) == false)
			targetcl->set_buf(this->set_log("404", targetcl->get_nickname(), temp_param[0] + " :Cannot send to channel"));
		else
		{
			std::string temp; // = targetcl->getUserPerfix();
    		std::vector<std::string>::iterator it = temp_param.begin();
    		std::advance(it, 1);
			if ((*it)[0] != ':')
				temp.append(":");
    		for (; it < temp_param.end(); it++)
        	{
        		temp.append(*it);
        		temp.append(" ");
    		}
    		temp.pop_back();
			this->access_server()->set_buf_of_cl_in_ch(
				temp_param[0], this->set_privte_log(targetcl->get_nickname(), "PRIVMSG", temp_param[0], temp), authfd);
		}
	}
	else
	{
		int sendcl = this->get_server()->get_cl_fd_by_nick(temp_param[0]);
		if (sendcl == ERROR)
			targetcl->set_buf(this->set_log("401", targetcl->get_nickname(), temp_param[0] + " :No such nick/channel"));
		else if(sendcl == authfd)
			targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), temp_param[0] + " :You can't send it to yourself."));
		else
		{
			std::string temp;
    		std::vector<std::string>::iterator it = temp_param.begin();
    		std::advance(it, 1);
			if ((*it)[0] != ':')
				temp.append(":");
    		for (; it < temp_param.end(); it++)
        	{
        		temp.append(*it);
        		temp.append(" ");
    		}
    		temp.pop_back();
			this->get_server()->get_cl().find(sendcl)->second->set_buf(
				this->set_privte_log(targetcl->get_nickname(), "PRIVMSG", targetcl->get_nickname(), temp));
		}
	}
}
