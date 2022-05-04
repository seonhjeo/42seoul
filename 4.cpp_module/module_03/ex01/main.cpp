/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:26:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 15:54:20 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav1("scav1");
	ScavTrap scav2("scav2");

	scav1.attack("enemy1");
	scav1.takeDamage(5);
	scav1.beRepaired(3);
	scav1.guardGate();

	std::cout << std::endl;

	ScavTrap scav3;
	ScavTrap scav4(scav1);
	scav4.takeDamage(2);
	ScavTrap scav5 = scav2;
	scav5.takeDamage(2);

	scav1.printStatus();
	scav2.printStatus();
	scav3.printStatus();
	scav4.printStatus();
	scav5.printStatus();

	return (0);
}
