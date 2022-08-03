#include "quit.hpp"


Quit::Quit(const Message &input, Server *server) : Command(input, server)
{
    execute();
}

Quit::~Quit()
{
}

void Quit::execute()
{
    int fd = this->get_message().get_sender_fd();
    std::map<int, Client*> cl = this->get_server()->get_cl();;


    if (this->get_message().get_params().size() > 0 && this->get_message().get_params().front().compare(":") != 0)
        cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), ":" + this->get_message().get_params()[0]));
    else
        cl[fd]->set_buf(this->set_log("998", cl[fd]->get_nickname(), ":Your connection has been terminated."));
    std::map<std::string, Channel*> channels = this->get_server()->get_ch();
    std::map<std::string, Channel*>::const_iterator it = channels.begin();
	std::map<std::string, Channel*>::const_iterator ite = channels.end();
    while (it != ite)
    {
        if ((*it).second->is_in_client(fd) == true)
        {
            std::string ch_msg = (*it).first;
            if ((*it).second->get_clients().size() == 1 && channels[ch_msg]->get_oper() == fd)
            {
                (*it).second->delete_client(fd);
                this->access_server()->channel_close(ch_msg);
            }
            else if ((*it).second->get_clients().size() > 1 )
            {
                if (channels[ch_msg]->get_oper() == fd)
                {
                    int n_fd = channels[ch_msg]->next_fd(fd);
                    if (n_fd == -1)
                        break ;
                    channels[ch_msg]->change_oper(n_fd);
                }
                channels[ch_msg]->delete_client(fd);
            }
        }
        it++;
    }

    if (cl[fd]->get_authorized() == true)
        cl[fd]->set_authorized(false);
    cl[fd]->set_is_quit(true);
	return ;
}
