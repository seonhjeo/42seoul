/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:48:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:29:00 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::~Dog()
{
}

Dog::Dog(Dog const &other) : Animal(other)
{
}

Dog &Dog::operator=(Dog const &other)
{
	this->Animal::operator=(other);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bow-wow!!!" << std::endl;
}
