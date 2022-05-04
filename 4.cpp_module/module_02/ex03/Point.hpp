/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:37:40 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 14:37:54 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const & src);
		Point(Fixed const x, Fixed const y);
		~Point();

		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
	private:
		Fixed const _x;
		Fixed const _y;
		
		Point & operator=(Point const & src);
};

#endif