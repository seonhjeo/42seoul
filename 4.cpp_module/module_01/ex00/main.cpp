/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:02:40 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 11:02:48 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;
	
	zombie1 = newZombie("zombie1");
	zombie2 = newZombie("zombie2");
    
	randomChump("zombie3");
    
	zombie2->announce();
	zombie1->announce();
    
	delete zombie1;
	delete zombie2;
    
	return (0);
}