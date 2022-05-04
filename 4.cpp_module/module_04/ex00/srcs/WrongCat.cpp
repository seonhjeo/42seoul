/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:12:41 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:29:06 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "Wrong Cat";
	std::cout << type << " is born" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->WrongAnimal::operator=(copy);
	return *this;
}
WrongCat::~WrongCat()
{
	std::cout << type << " is dead" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!!" << std::endl;
}
