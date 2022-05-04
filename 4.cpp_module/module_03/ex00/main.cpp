/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:26:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/07 13:04:18 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap1("clap1");
	ClapTrap clap2("clap2");

	clap1.attack("enemy1");
	clap1.takeDamage(5);
	clap1.beRepaired(3);

	ClapTrap clap3;
	ClapTrap clap4(clap1);
	clap3.takeDamage(2);
	clap1.beRepaired(0);
	ClapTrap clap5 = clap2;
	clap5.takeDamage(2);
	clap2.beRepaired(0);

	return (0);
}
