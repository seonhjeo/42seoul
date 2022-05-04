/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:04:43 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/10 15:49:26 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);
	~Brain();

	std::string const &getIdea(int index) const;
};

#endif
