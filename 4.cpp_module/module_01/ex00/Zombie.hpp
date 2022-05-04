/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:59:42 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 10:45:18 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie
{
private:
    std::string _name;
public:
    Zombie(std::string name);
    ~Zombie();

    void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif