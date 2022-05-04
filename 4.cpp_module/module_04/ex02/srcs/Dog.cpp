/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:48:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/10 17:43:17 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->brain = new Brain();
}

Dog::~Dog()
{
	delete this->brain;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	this->brain = new Brain(*other.getBrain());
}

Dog &Dog::operator=(Dog const &other)
{
	if (this != &other)
	{
		this->~Dog();
		this->brain = new Brain(*other.getBrain());
		this->Animal::operator=(other);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bow-wow!!!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}
