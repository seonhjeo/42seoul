/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:11:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:34:23 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "Wrong Animal";
	std::cout << type << " is born" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.getType();
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << type << " is dead" << std::endl;
}
std::string const &WrongAnimal::getType() const
{
	return this->type;
}
void WrongAnimal::makeSound() const
{
	std::cout << "Animal Animal!!!" << std::endl;
}
