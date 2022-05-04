/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:04:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 14:40:26 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
}
Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}
Fixed::Fixed(const int fixed)
{
    _value = fixed << _bits;
}
Fixed::Fixed(const float fixed)
{
    _value = roundf(fixed * (1 << _bits));
}
Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
    this->_value = fixed.getRawBits();
    return (*this);
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}
Fixed Fixed::operator-(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}
Fixed Fixed::operator*(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}
Fixed Fixed::operator/(Fixed const &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}
Fixed &Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}
Fixed Fixed::operator++(int)
{
    Fixed	f(*this);

	this->_value++;
	return (f);
}
Fixed Fixed::operator--(int)
{
    Fixed	f(*this);

	this->_value--;
	return (f);
}

bool Fixed::operator>(Fixed const &fixed) const
{
    return (this->_value > fixed._value);
}
bool Fixed::operator<(Fixed const &fixed) const
{
    return (this->_value < fixed._value);
}
bool Fixed::operator>=(Fixed const &fixed) const
{
    return (this->_value >= fixed._value);
}
bool Fixed::operator<=(Fixed const &fixed) const
{
    return (this->_value <= fixed._value);
}
bool Fixed::operator==(Fixed const &fixed) const
{
    return (this->_value == fixed._value);
}
bool Fixed::operator!=(Fixed const &fixed) const
{
    return (this->_value != fixed._value);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}
void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

float Fixed::toFloat( void ) const
{
    return (float(_value) / (1 << _bits));
}
int Fixed::toInt( void ) const
{
    return (_value >> _bits);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
		return (f1);
	return (f2);
}
Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
    if (f1 < f2)
		return (f1);
	return (f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1 > f2)
		return (f1);
	return (f2);
}
Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
    if (f1 > f2)
		return (f1);
	return (f2);
}

std::ostream &	operator<<(std::ostream &out, const Fixed & fixed)
{
    out << fixed.toFloat();
	return out;
}