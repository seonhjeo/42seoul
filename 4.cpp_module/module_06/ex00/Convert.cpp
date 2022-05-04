/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:14:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/08 17:07:56 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <limits>
#include <string>
#include <cmath>

Convert::Convert(Convert const &other) : _input(other.getValue()) {}

Convert &Convert::operator=(const Convert &other)
{
	this->_input = other.getValue();
	return (*this);
}

std::string const &Convert::getValue() const
{
	return (this->_input);
}

char Convert::toChar() const
{
	char *ptr = NULL;
	const char *input = _input.c_str();
	int n;

	try
	{
		n = static_cast<int>(std::strtod(input, &ptr));
		if (n < 0 || n > CHAR_MAX)
			throw(Convert::ImpossibleException());
		if (*ptr && std::strcmp(ptr, "f"))
			throw(Convert::ImpossibleException());
	}
	catch(...)
	{
		throw(Convert::ImpossibleException());
	}
	if (!isprint(n))
		throw(Convert::NonDisplayableException());
	return (static_cast<char>(n));
}

int Convert::toInt() const
{
	char *ptr = NULL;
	const char *input = _input.c_str();
	int n;

	try
	{
		n = static_cast<int>(std::strtod(input, &ptr));
		if (*ptr && std::strcmp(ptr, "f"))
			throw(Convert::ImpossibleException());
	}
	catch(...)
	{
		throw(Convert::ImpossibleException());
	}
	return (n);
}

float Convert::toFloat() const
{
	char *ptr = NULL;
	const char *input = _input.c_str();
	float n;

	try
	{
		n = static_cast<float>(std::strtod(input, &ptr));
		if (*ptr && std::strcmp(ptr, "f"))
			throw(Convert::ImpossibleException());
	}
	catch(...)
	{
		throw(Convert::ImpossibleException());
	}
	return (n);
}

double Convert::toDouble() const
{
	char *ptr = NULL;
	const char *input = _input.c_str();
	double n;

	try
	{
		n = std::strtod(input, &ptr);
		if (*ptr && std::strcmp(ptr, "f"))
			throw(Convert::ImpossibleException());
	}
	catch(...)
	{
		throw(Convert::ImpossibleException());
	}
	return (n);
}

std::ostream &operator<<(std::ostream &os, const Convert &convert)
{
	os << "char: ";
	try
	{
		char c = convert.toChar();
		os << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "int: ";
	try
	{
		os << convert.toInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "float: ";
	try
	{
		float f = convert.toFloat();

		if (std::isnan(f) && std::signbit(f))
			os << "-";
		os << f;
		if (!std::isnan(f) && f - (int)f == 0)
			os << ".0";
		os << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}

	os << "Double: ";
	try
	{
		double d = convert.toDouble();

		if (std::isnan(d) && std::signbit(d))
			os << "-";
		os << d;
		if (!std::isnan(d) && d - (int)d == 0)
			os << ".0";
		os << std::endl;
	}
	catch (const std::exception &e)
	{
		os << e.what() << std::endl;
	}
	return (os);
}
