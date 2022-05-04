/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:50:59 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/09 15:52:19 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string const &other);
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);
	virtual ~WrongAnimal();
	std::string const &getType() const;
	void makeSound() const;
};

#endif
