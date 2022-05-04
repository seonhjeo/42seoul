#ifndef CONVERT_HPP
#define CONVERT_HPP

# include <iostream>

class Convert
{
private:
	std::string _input;
	Convert() : _input("") {};
public:
	Convert(std::string const &input) : _input(input) {};
	Convert(Convert const &other);
	~Convert() {};
	Convert &operator=(const Convert &other);

	std::string const &getValue() const;

	char toChar() const;
	int toInt() const;
	float toFloat() const;
	double toDouble() const;

	class ImpossibleException : public std::exception
	{
		const char *what() const throw()
		{
			return ("impossible");
		}
	};

	class NonDisplayableException : public std::exception
	{
		const char *what() const throw()
		{
			return ("Non displayable");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Convert &convert);

#endif
