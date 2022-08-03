#include "command.hpp"

Command::Command(const Message &input, Server *server) : _input(input), _server(server) {};

Command::~Command() {};

std::string     Command::set_log(std::string num, std::string target, std::string log)
{
	if (target == "")
		target = "*";
	log = ":" + std::string(SERVER_NAME) + " " + num + " " + target + " " + log;
	int len = log.size() > BUFFER_MAX ? BUFFER_MAX : log.size();
	log.substr(len);
	log += "\r\n";
	return (log);
}

std::string     Command::set_privte_log(std::string nick, std::string num, std::string target, std::string log)
{
    if (target == "")
        target = "*";
    log = ":" + nick + " " + num + " " + target + " " + log;
    int len = log.size() > BUFFER_MAX ? BUFFER_MAX : log.size();
    log.substr(len);
    log += "\r\n";
    return (log);
}

const Server*	Command::get_server(void)
{
	return (this->_server);
}

Server*		Command::access_server(void)
{
	return (this->_server);
}

const Message	&Command::get_message(void) const
{
	return (this->_input);
}
