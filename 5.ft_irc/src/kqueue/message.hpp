#ifndef MESSAGE_HPP
# define MESSAGE_HPP

# include <string>
# include <vector>
# include <algorithm>

class Message
{
private:
	int							_sender_fd;
	std::string					_buffer; 
	std::string					_command;
	std::vector<std::string>	_params;

	Message();
	void Parse();

public:
	Message(int &sender_fd, std::string &buffer);
	Message(const Message &other);
	Message &operator=(const Message &other);
	~Message();

	int								get_sender_fd() const;
	const std::string				get_buffer() const;
	const std::string				get_command() const;
	const std::vector<std::string>	get_params() const;
};
#endif