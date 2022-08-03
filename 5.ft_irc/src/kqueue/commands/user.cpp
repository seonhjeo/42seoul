#include "user.hpp"

User::User(const Message &input, Server *server) : Command(input, server)
{
    execute();
};

User::~User() {};

void User::execute()
{
    int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();

    if (targetcl->get_authorized() == false)
    {
        targetcl->set_buf(this->set_log("451", targetcl->get_nickname(), ":You have not registered"));
        return ;
    }

    if (temp_param.size() < 4)
    {
        targetcl->set_buf(this->set_log("461", targetcl->get_nickname(), "USER :Not enough parameters"));
        return ;
    }

    if (temp_param[1] != "0" || temp_param[2] != "*")
    {
        targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), ":We don't support flag or modes, right form is 'USER <username> 0 * <realname>'"));
        return ;
    }

    if (targetcl->get_username() != "")
    {
        targetcl->set_buf(this->set_log("462", targetcl->get_nickname(), ":Unauthorized command (already registered)"));
        return ;
    }
    
    targetcl->set_username(temp_param[0]);

    std::string temp;
    std::vector<std::string>::iterator it = temp_param.begin();
    std::advance(it, 3);
    for (; it < temp_param.end(); it++)
    {
        temp.append(*it);
        temp.append(" ");
    }
    temp.pop_back();
    targetcl->set_realname(temp);
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":Successfully set your user config"));
    targetcl->set_buf(this->set_log("001", targetcl->get_nickname(), "Welcome to the Internet Relay Network\n"
        + targetcl->get_nickname() + "!" + targetcl->get_username() + "@" + std::string(SERVER_DOMAIN)));
}
