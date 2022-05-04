/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:51:44 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 11:45:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int _value;
    const static int _bits;
public:
    Fixed(void);
    Fixed(const int fixed);
    Fixed(const float fixed);
    Fixed(const Fixed &fixed);
    ~Fixed(void);

    Fixed &operator=(Fixed const &fixed);

    int getRawBits(void) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &	operator<<(std::ostream &out, const Fixed &fixed);

#endif