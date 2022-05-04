/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:54:22 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 15:30:47 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap()
{
	std::cout << "ScavTrap overrided" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "ScavTrap overrided" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other):ClapTrap(other)
{
	std::cout << "ScavTrap overrided" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap::";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	ClapTrap::operator=(other);
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap::";
	this->ClapTrap::attack(target);
}
void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap::";
	this->ClapTrap::takeDamage(amount);
}
void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap::";
	this->ClapTrap::beRepaired(amount);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap name " << this->_name << " Gate keeper mode ON" << std::endl;
}

void ScavTrap::printStatus()
{
	std::cout << "ScavTrap::";
	this->ClapTrap::printStatus();
}
