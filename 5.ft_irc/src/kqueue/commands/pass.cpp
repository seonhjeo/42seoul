#include "pass.hpp"

Pass::Pass(const Message &input, Server *server) : Command(input, server)
{
    execute();
};

Pass::~Pass() {};

void Pass::execute()
{
    int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;
    std::vector<std::string> temp_param = this->get_message().get_params();

    if (temp_param.size() != 1)
    {
        targetcl->set_buf(this->set_log("461", targetcl->get_nickname(), "PASS :Not enough parameters"));
        return ;
    }

    if (targetcl->get_authorized() == true)
    {
        targetcl->set_buf(this->set_log("462", targetcl->get_nickname(), ":Unauthorized command (already registered)"));
        return ;
    }

    if (temp_param[0] != this->get_server()->get_pw())
    {
        targetcl->set_buf(this->set_log("999", targetcl->get_nickname(), ":Incorrect password"));
        return ;
    }
    targetcl->set_authorized(true);
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":You are authorized successfully"));
}
