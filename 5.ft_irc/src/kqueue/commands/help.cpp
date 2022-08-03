#include "help.hpp"

Help::Help(const Message &input, Server *server) : Command(input, server)
{
    execute();
};

Help::~Help() {};

void Help::execute()
{
    int authfd = this->get_message().get_sender_fd();
    Client* targetcl = this->get_server()->get_cl().find(authfd)->second;

    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":This is ft_irc by JBS"));\
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":First you have to authorize by PASS command"));
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":Then use NICK command to set your nickname"));
    targetcl->set_buf(this->set_log("998", targetcl->get_nickname(), ":And then use USER command to set your config"));
}
