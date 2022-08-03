#include "nick.hpp"

Nick::Nick(const Message &input, Server *server) : Command(input, server)
{
    execute();
};

Nick::~Nick() {};

void Nick::execute()
{
    int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();

    if (targetcl->get_authorized() == false)
    {
        targetcl->set_buf(this->set_log("451", targetcl->get_nickname(), ":You have not registered"));
        return ;
    }

    if (temp_param.size() < 1)
    {
        targetcl->set_buf(this->set_log("431", targetcl->get_nickname(), ":No nickname given"));
        return ;
    }

    std::string tempnick = temp_param[0];
    if (tempnick.length() > CLIENT_NICKNAME_MAX)
    {
        targetcl->set_buf(this->set_log("432", targetcl->get_nickname(), tempnick + " :Erroneous nickname"));
        return ;
    }

    const char *tempcnick = tempnick.c_str();
    for (size_t i = 0; i < tempnick.size(); i++)
    {
        if (!(islower(tempcnick[i]) || isdigit(tempcnick[i])))
        {
            targetcl->set_buf(this->set_log("432", targetcl->get_nickname(), tempnick + " :Erroneous nickname"));
            return ;
        }
    }

    if (this->get_server()->get_cl_fd_by_nick(tempnick) != ERROR)
    {
        targetcl->set_buf(this->set_log("433", targetcl->get_nickname(), tempnick + " :Nickname is already in use"));
        return ;
    }

    targetcl->set_nickname(tempnick);
    targetcl->set_check_time(1);
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":Successfully change your nickname"));
}
