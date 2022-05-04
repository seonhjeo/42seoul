/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:40:02 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 12:22:58 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie	*zombies;
	int		i;

	zombies = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombies[i].setName(name + std::to_string(i));
		i++;
	}
	return (zombies);
}