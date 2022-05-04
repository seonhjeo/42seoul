/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:25:59 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/11 15:29:20 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
	Ice();
	Ice(Ice const &other);
	~Ice();

    Ice &operator=(Ice const &other);
    
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif