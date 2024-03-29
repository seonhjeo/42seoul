/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:38:48 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 14:38:50 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int 	cross_count = 0;
	Fixed	check_x;
	
	if ((a.get_y() > point.get_y()) != (b.get_y() > point.get_y()))
	{
		check_x = (b.get_x() - a.get_x()) * (point.get_y() - a.get_y()) / (b.get_y() - a.get_y()) + a.get_x();
		if (point.get_x() < check_x)
			cross_count++;
	}


	if ((b.get_y() > point.get_y()) != (c.get_y() > point.get_y()))
	{
		check_x = (c.get_x() - b.get_x()) * (point.get_y() - b.get_y()) / (c.get_y() - b.get_y()) + b.get_x();
		if (point.get_x() < check_x)
			cross_count++;
	}

	if ((c.get_y() > point.get_y()) != (a.get_y() > point.get_y()))
	{
		check_x = (a.get_x() - c.get_x()) * (point.get_y() - c.get_y()) / (a.get_y() - c.get_y()) + c.get_x();
		if (point.get_x() < check_x)
			cross_count++;
	}
	
	return (cross_count % 2 == 1);
}