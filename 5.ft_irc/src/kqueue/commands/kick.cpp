#include "kick.hpp"

Kick::Kick(const Message &input, Server *server) : Command(input, server)
{
	execute();
};

Kick::~Kick() {};

void Kick::execute()
{
    int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();

    if (targetcl->get_authorized() == false)
    {
        targetcl->set_buf(this->set_log("451", targetcl->get_nickname(), ":You have not registered"));
        return ;
    }

    if (temp_param.size() < 2)
    {
        targetcl->set_buf(this->set_log("461", targetcl->get_nickname(), "KICK :Not enough parameters"));
        return ;
    }
    
    std::map<std::string, Channel*> targetchmap = this->get_server()->get_ch();
    Channel* targetch = targetchmap.find(temp_param[0])->second;

    if (targetchmap.find(temp_param[0]) == targetchmap.end())
    {
        targetcl->set_buf(this->set_log("403", targetcl->get_nickname(), temp_param[0] + " :No such channel"));
        return ;
    }

    if (targetch->get_oper() != authfd)
    {
        targetcl->set_buf(this->set_log("482", targetcl->get_nickname(), temp_param[0] + " :You're not channel operator"));
        return ;
    }

    std::map<int, Client*> targetclmap = this->access_server()->get_cl();
    int kicktargetclfd = this->get_server()->get_cl_fd_by_nick(temp_param[1]);

    if (kicktargetclfd == ERROR)
    {
        targetcl->set_buf(this->set_log("441", targetcl->get_nickname(), temp_param[1] + " " + temp_param[0] + " :They aren't on that channel"));
        return ;
    } 

    targetch->delete_client(kicktargetclfd);
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), temp_param[1] + " " + temp_param[0] + " :Successfully kick user"));

    Client* kicktargetcl = targetclmap.find(kicktargetclfd)->second;
    if (temp_param.size() == 2)
        kicktargetcl->set_buf(this->set_log("998", targetcl->get_nickname(), temp_param[1] + " " + temp_param[0] + " :You are kicked"));
    else
        kicktargetcl->set_buf(this->set_log("998", targetcl->get_nickname(), temp_param[1] + " " + temp_param[0] + " :" + temp_param[2]));  
}
