/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:28:57 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(Cat const &other) : Animal(other)
{
}

Cat::~Cat()
{
}

Cat &Cat::operator=(Cat const &other)
{
	this->Animal::operator=(other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
}
