/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:25:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 15:15:34 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(void)
{
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string	&Weapon::getType(void)
{
	return _type;
}