/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/10 17:43:16 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->brain = new Brain();
}

Cat::~Cat()
{
	delete this->brain;
}

Cat::Cat(Cat const &other) : Animal(other)
{
	this->brain = new Brain(*other.getBrain());
}

Cat &Cat::operator=(Cat const &other)
{
	if (this != &other)
	{
		this->~Cat();
		this->brain = new Brain(*other.getBrain());
		this->Animal::operator=(other);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}
