#include "message.hpp"

Message::Message() {};

Message::Message(int &sender_fd, std::string &buffer) : _sender_fd(sender_fd), _buffer(buffer)
{
	Parse();
};

Message::Message(const Message &other)
{
	this->_sender_fd = other.get_sender_fd();
	this->_buffer = other.get_buffer();
	this->_command = other.get_command();
	this->_params = other.get_params();
}

Message	&Message::operator=(const Message &other)
{
	this->_sender_fd = other.get_sender_fd();
	this->_buffer = other.get_buffer();
	this->_command = other.get_command();
	this->_params = other.get_params();

	return (*this);
}

Message::~Message()
{
	this->_params.clear();
}

int		Message::get_sender_fd() const
{
	return (this->_sender_fd);
}

const std::string	Message::get_buffer() const
{
	return (this->_buffer);
}

const std::string	Message::get_command() const
{
	return (this->_command);
}

const std::vector<std::string>	Message::get_params() const
{
	return (this->_params);
}

// 입력받은 buffer를 command와 params로 파싱하는 함수
// 단순 스페이스를 이용해 문자열들을 나눈다.
void	Message::Parse()
{
	if (this->_buffer.back() == '\n')
		this->_buffer.pop_back();
	if (this->_buffer.back() == '\r')
		this->_buffer.pop_back();

	std::string s(this->_buffer);
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		if (token.size() == 0)
			;
		else if (_command.size() == 0)
			_command = token;
		else 
			_params.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	token = s.substr(0, pos);
	if (token.size() == 0)
		;
	else if (_command.size() == 0)
		_command = token;
	else 
		_params.push_back(token);
}
