/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:27:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/10 19:35:07 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;
public:
	Animal();
	Animal(std::string const &type);
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
	virtual ~Animal();

	std::string const &getType() const;
	virtual void makeSound() const = 0;
};

#endif
