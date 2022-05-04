/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:02:21 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/15 12:39:03 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size) : _size(size) {}

Span::Span(Span const &other)
{
	_size = other.getSize();
	_values = other.getValues();
}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		this->_size = other.getSize();
		this->_values = other.getValues();
	}
	return (*this);
}

Span::~Span() {}

int &Span::operator[](int i)
{
	if (i < 0)
		throw Span::OutOfRangeException();
	if (static_cast<unsigned int>(i) >= this->_size)
		throw Span::OutOfRangeException();
	return (_values[i]);
}

unsigned int Span::getSize() const
{
	return (_size);
}
std::vector<int> const &Span::getValues() const
{
	return (_values);
}

void Span::addNumber(int n)
{
	if (_values.size() >= _size)
		throw Span::FullException();
	_values.push_back(n);
}
void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	int inputSize = std::distance(begin, end);
	int thisSize = _values.size();

	if (inputSize + thisSize > static_cast<int>(_size))
		throw Span::FullException();
	_values.insert(_values.end(), begin, end);
}
unsigned int Span::shortestSpan() const
{
	if (_values.size() < 2)
		throw Span::CantSpanException();
	std::vector<int> copy = _values;

	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator prev_it = copy.begin();
	std::vector<int>::iterator next_it = ++copy.begin();
	unsigned int minSpan = *next_it - *prev_it;

	while (next_it != copy.end())
	{
		if (*next_it - *prev_it < static_cast<int>(minSpan))
			minSpan = *next_it - *prev_it;
		prev_it = next_it;
		next_it++;
	}
	return minSpan;
}
unsigned int Span::longestSpan() const
{
	if (_values.size() < 2)
		throw Span::CantSpanException();
	std::vector<int> copy = _values;

	std::sort(copy.begin(), copy.end());

	return (copy.back() - copy.front());
}
