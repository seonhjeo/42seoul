/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:14:46 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 16:01:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
private:
    std::string _type;
public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();

    void    setType(std::string type);
    const std::string &getType(void);
};

#endif