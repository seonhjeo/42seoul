/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:27:06 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 15:43:27 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with his ";
	if (_weapon == NULL)
		std::cout << "fist" << std::endl;
	else
		std::cout << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}