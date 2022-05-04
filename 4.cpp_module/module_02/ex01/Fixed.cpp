/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:04:49 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/18 11:56:48 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int fixed)
{
    std::cout << "Int constructor called" << std::endl;
    _value = fixed << _bits;
}
Fixed::Fixed(const float fixed)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(fixed * (1 << _bits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destrutor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_value = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
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

std::ostream &	operator<<(std::ostream &out, const Fixed & fixed)
{
    out << fixed.toFloat();
	return out;
}