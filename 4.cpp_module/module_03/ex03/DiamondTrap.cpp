/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:19:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/08 13:06:38 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap inherited" << std::endl;
	this->_name = "default";
	this->ClapTrap::_name = "default_clap_name";
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap inherited" << std::endl;
	this->_name = name;
	this->FragTrap::_hitPoints = 100;
	this->ScavTrap::_energyPoints = 50;
	this->FragTrap::_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap inherited" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap::";
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "DiamondTrap::";
	this->_name = other._name;
	this->ClapTrap::_name = other.ClapTrap::_name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

void DiamondTrap::attack(std::string const & target)
{
	std::cout << "DiamondTrap::";
	this->ScavTrap::attack(target);
}
void DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap::";
	this->ScavTrap::takeDamage(amount);
}
void DiamondTrap::beRepaired(unsigned int amount)
{
	std::cout << "DiamondTrap::";
	this->ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << _name << ", my base name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStatus()
{
	std::cout << "name : " << this->_name << std::endl;
	std::cout << "DiamondTrap::";
	this->FragTrap::printStatus();
}
