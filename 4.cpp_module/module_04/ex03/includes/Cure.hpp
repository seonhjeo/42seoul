/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:30:34 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/11 15:46:49 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:
	
public:
	Cure();
	Cure(Cure const &other);	
	~Cure();

    Cure &operator=(Cure const &other);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif