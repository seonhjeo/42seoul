#include "join.hpp"
#include <algorithm>
#include <utility>

Join::Join(const Message &input, Server *server): Command(input, server)
{
	this->execute();
}

Join::~Join()
{}

bool	Join::check_word(std::string param)
{
	for (size_t i = 1; i < param.length(); ++i)
	{
		if (!('a' <= param[i] && param[i] <= 'z')
			&& !('A' <= param[i] && param[i] <= 'Z')
			&& !('0' <= param[i] && param[i] <= '9'))
			return (false);
	}
	return (true);
}

void	Join::execute()
{
	int	authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();
	if (targetcl->get_authorized() == false)
	{
        targetcl->set_buf(this->set_log("451", targetcl->get_nickname(), ":You have not registered"));
        return ;
	}
	if (temp_param.size() == 0)
	{
		targetcl->set_buf(this->set_log("461", targetcl->get_nickname(), "JOIN :Not enough parameters"));
        return ;
	}
	if (temp_param.size() > 3)
	{
		targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), "JOIN :Too many parameters"));
        return ;
	}
	if (temp_param[0].size() > 50)
	{
		targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), "JOIN :Too long parameters"));
        return ;
	}
	if (check_word(temp_param[0]) == false)
	{
		targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), "JOIN :Wrong word in parameters"));
        return ;
	}
	if (temp_param[0][0] != '&' && temp_param[0][0] != '#' && temp_param[0][0] != '!' && temp_param[0][0] != '+')
	{
		targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), ":Bad arguments [&, #, + or !]<channel>"));
		return ;
	}

	std::map<std::string, Channel*> channels = this->get_server()->get_ch();
	if (channels.find(temp_param[0]) == channels.end())
	{	// Server 생성
		if (temp_param.size() == 2)
			this->access_server()->add_channel(temp_param[0], temp_param[1], authfd);
		else
			this->access_server()->add_channel(temp_param[0], "", authfd);
	}
	
	channels = this->get_server()->get_ch();
	Channel*	cur_channel = channels[temp_param[0]];
	if (temp_param.size() == 2 && cur_channel->get_password() != temp_param[1])
		targetcl->set_buf(this->set_log("475", targetcl->get_nickname(), temp_param[0] + " :Cannot join channel (+b)"));
	else if (cur_channel->add_client(authfd) == -1)
    	targetcl->set_buf(this->set_log("443", targetcl->get_nickname(), targetcl->get_nickname() + " " + temp_param[0] + " :is already on channel"));
	else
    	targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":Success to join " + temp_param[0]));
}
