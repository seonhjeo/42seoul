/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:12:13 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/31 15:15:34 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <algorithm>

class NoElementException : public std::exception
{
public:
	const char *what() const throw()
	{
		return ("Has no Elements");
	}
};

template <typename T>
typename T::iterator easyfind(T &container, const int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw  NoElementException();
	return it;
};

template <typename T>
typename T::const_iterator easyfind(const T &container, const int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw  NoElementException();
	return it;
};

#endif
