/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:26:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 15:54:08 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag1("frag1");
	FragTrap frag2("frag2");

	frag1.attack("enemy1");
	frag1.takeDamage(5);
	frag1.beRepaired(3);
	frag1.highFivesGuys();

	std::cout << std::endl;

	FragTrap frag3;
	FragTrap frag4(frag1);
	frag4.takeDamage(2);
	FragTrap frag5 = frag2;
	frag5.takeDamage(2);

	frag1.printStatus();
	frag2.printStatus();
	frag3.printStatus();
	frag4.printStatus();
	frag5.printStatus();

	return (0);
}
