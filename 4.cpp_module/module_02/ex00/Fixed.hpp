/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:51:44 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/17 17:19:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int _raw;
    const static int _bits;
public:
    Fixed(void);
    Fixed(const Fixed &fixed);
    ~Fixed(void);

    Fixed &operator=(Fixed const &fixed);

    int getRawBits(void) const;
    void setRawBits( int const raw ); 
};

#endif