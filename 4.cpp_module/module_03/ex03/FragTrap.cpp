/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:23:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/08 12:48:48 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void):ClapTrap()
{
	std::cout << "FragTrap inherited" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const &name):ClapTrap(name)
{
	std::cout << "FragTrap inherited" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other):ClapTrap(other)
{
	std::cout << "FragTrap inherited" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap::";
}

FragTrap &FragTrap::operator=(FragTrap const &other)
{
	ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap::";
	this->ClapTrap::attack(target);
}
void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap::";
	this->ClapTrap::takeDamage(amount);
}
void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << "FragTrap::";
	this->ClapTrap::beRepaired(amount);
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap name " << this->_name << " do positive Highfives" << std::endl;
}

void FragTrap::printStatus()
{
	std::cout << "FragTrap::";
	this->ClapTrap::printStatus();
}
