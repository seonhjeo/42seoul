/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:03:26 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 17:41:27 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

static int getKarenFilter(std::string msg)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == msg)
			return (i);
	}
	return (4);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	enum levels
	{
		DEBUG = 0,
		INFO = 1,
		WARNING = 2,
		ERROR = 3,
	};
	Karen karen;

	switch (getKarenFilter(av[1]))
	{
	case DEBUG:
		karen.complain("DEBUG");
		std::cout << std::endl;
	case INFO:
		karen.complain("INFO");
		std::cout << std::endl;
	case WARNING:
		karen.complain("WARNING");
		std::cout << std::endl;
	case ERROR:
		karen.complain("ERROR");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}