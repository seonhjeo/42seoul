/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:26:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/08 12:53:33 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond1("diamond1");
	DiamondTrap diamond2("diamond2");

	diamond1.attack("enemy1");
	diamond1.takeDamage(5);
	diamond1.beRepaired(3);
	diamond1.highFivesGuys();
	diamond1.guardGate();
	diamond1.whoAmI();

	std::cout << std::endl;

	DiamondTrap diamond3;
	DiamondTrap diamond4(diamond1);
	diamond4.takeDamage(2);
	DiamondTrap diamond5 = diamond2;
	diamond5.takeDamage(2);

	diamond1.printStatus();
	diamond2.printStatus();
	diamond3.printStatus();
	diamond4.printStatus();
	diamond5.printStatus();

	return (0);
}
