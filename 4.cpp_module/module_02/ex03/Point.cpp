/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:38:05 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 14:38:07 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point & src) : _x(src._x), _y(src._y)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point &	Point::operator=(Point const & src)
{
	(void)src;
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}