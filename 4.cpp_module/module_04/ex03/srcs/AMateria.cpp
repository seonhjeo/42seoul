/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:36:37 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/11 15:25:56 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
    this->_type = type;
}
AMateria::AMateria(AMateria const &other)
{
    this->_type = other._type;
}
AMateria &AMateria::operator=(AMateria const &other)
{
    this->_type = other._type;
    return (*this);
}
AMateria::~AMateria()
{
    
}

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    
}