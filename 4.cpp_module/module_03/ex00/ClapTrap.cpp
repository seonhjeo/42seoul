/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:06:24 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 13:36:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Make new Claptrap without name" << std::endl << std::endl;
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "Make new Claptrap name " << name << std::endl << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy and make new Claptrap from " << other._name << " by Copy Constructor" << std::endl << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy and make new Claptrap from " << other._name << " by Operator =" << std::endl << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Remove Claptrap name " << _name << std::endl << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has taken "
			<< amount << " points of damage!" << std::endl;
	_energyPoints -= amount;
	std::cout << "ClapTrap " << _name << " now has "
			<< _energyPoints << " points of energe points!" << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has been repared "
			<< amount << " points of energe!" << std::endl;
	_energyPoints += amount;
	std::cout << "ClapTrap " << _name << " now has "
			<< _energyPoints << " points of energe points!" << std::endl << std::endl;
}
