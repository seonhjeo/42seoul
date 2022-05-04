/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:59:14 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 12:16:56 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() { }

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << _name << " is dead" << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << _name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}