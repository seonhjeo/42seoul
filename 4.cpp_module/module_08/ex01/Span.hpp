/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:21:39 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/15 12:31:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
private:
	unsigned int _size;
	std::vector<int> _values;
	Span();
public:
	Span(unsigned int n);
	Span(Span const &other);
	Span &operator=(Span const &other);
	int &operator[](int i);
	~Span();

	unsigned int getSize() const;
	std::vector<int> const &getValues() const;

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class OutOfRangeException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Out of range");
		}
	};
	class FullException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Buffer is already full");
		}
	};
	class CantSpanException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Can't Span");
		}
	};

};

#endif
