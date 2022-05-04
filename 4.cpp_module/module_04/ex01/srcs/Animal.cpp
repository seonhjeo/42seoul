/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:40:24 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:29:18 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
	this->_type = "Some animal";
	std::cout << this->_type << " born" << std::endl;
}

Animal::Animal(std::string const &type)
{
	this->_type = type;
	std::cout << this->_type << " born" << std::endl;
}

Animal::Animal(Animal const &other)
{
	*this = other;
	std::cout << this->_type << " born by copy" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	this->_type = other.getType();
	std::cout << this->_type << " born by oper" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << this->_type << " dead" << std::endl;
}

std::string const &Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Some animal make sound" << std::endl;
}
