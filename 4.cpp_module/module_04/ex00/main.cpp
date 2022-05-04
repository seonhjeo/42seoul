/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:13:13 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 16:32:51 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"

#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	{
		const Animal *meta = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		const WrongAnimal *wrong = new WrongCat();
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();
		wrong->makeSound();
		delete meta;
		delete cat;
		delete dog;
		delete wrong;
	}
	system("leaks myAnimal");
	return (0);
}
