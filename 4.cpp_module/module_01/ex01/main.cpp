/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:18:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 12:19:38 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombies;
	int		i;

	zombies = zombieHorde(10, "zombie");
	while (i < 10)
	{
		zombies[i].announce();
		i++;
	}
	delete[] zombies;
	return (0);
}