/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:51:44 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 14:22:30 by seonhjeo         ###   ########.fr       */
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
    
    Fixed operator+(Fixed const &fixed) const;
    Fixed operator-(Fixed const &fixed) const;
    Fixed operator*(Fixed const &fixed) const;
    Fixed operator/(Fixed const &fixed) const;
    
    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    bool operator>(Fixed const &fixed) const;
    bool operator<(Fixed const &fixed) const;
    bool operator>=(Fixed const &fixed) const;
    bool operator<=(Fixed const &fixed) const;
    bool operator==(Fixed const &fixed) const;
    bool operator!=(Fixed const &fixed) const;

    int getRawBits(void) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    static Fixed &min(Fixed &f1, Fixed &f2);
	static Fixed const &min(Fixed const &f1, Fixed const &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static Fixed const &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &	operator<<(std::ostream &out, const Fixed &fixed);

#endif