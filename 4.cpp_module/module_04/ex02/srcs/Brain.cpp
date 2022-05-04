/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:50:35 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/10 16:33:32 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	const std::string ideas[] = {
		"🥱",
		"🥵",
		"😢",
		"😱",
		"🥶",
		"🤯",
		"🤩",
		"🥰",
		"🥳",
		"🥴",
		"🤤",
		"🤢",
		"🤧",
		"🤮",
		"🤡",
		"🤠",
		"🤥",
		"🤤",
	};

	std::cout << "Constructor Brain:";
	for (int i = 0; i < 100; ++i)
	{
		this->ideas[i] = ideas[rand() % (sizeof(ideas) / sizeof(std::string))];
		std::cout << " " << this->ideas[i];
	}
	std::cout << std::endl;
}

Brain::Brain(Brain const &other)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.getIdea(i);
}

Brain &Brain::operator=(Brain const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.getIdea(i);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain:";
	for (int i = 0; i < 100; ++i)
		std::cout << " " << this->ideas[i];
	std::cout << std::endl;
}

std::string const &Brain::getIdea(int index) const
{
	return this->ideas[index];
}
