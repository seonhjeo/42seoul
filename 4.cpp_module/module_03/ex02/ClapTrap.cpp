/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:06:24 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 14:44:19 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap without name is made" << std::endl;
	this->_name = "";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "ClapTrap name " << name << " is made" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap name " << other._name << " is made by Copy Constructor" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap name " << other._name << " is made by Operator=" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap name " << _name << " removed" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
			<< _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has taken "
			<< amount << " points of damage!" << std::endl;
	_energyPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " has been repared "
			<< amount << " points of energe!" << std::endl;
	_energyPoints += amount;
}

void ClapTrap::printStatus(void)
{
	std::cout << "Claptrap " << this->_name << "'s current status" << std::endl;
	std::cout << "hitPoint : " << this->_hitPoints << std::endl;
	std::cout << "energyPoint : " << this->_energyPoints << std::endl;
	std::cout << "attackDamage : " << this->_attackDamage << std::endl << std::endl;
}
