/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:01:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/15 17:41:41 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Karen.hpp"

void Karen::debug(void)
{
	std::cerr << "[ DEBUG ]" << std::endl
              << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"
			  << std::endl;
}

void Karen::info(void)
{
	std::cerr << "[ INFO ]" << std::endl
              << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"
			  << std::endl;
}

void Karen::warning(void)
{
	std::cerr << "[ WARNING ]" << std::endl
              << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."
			  << std::endl;
}

void Karen::error(void)
{
	std::cerr << "[ ERROR ]" << std::endl
              << "This is unacceptable, I want to speak to the manager now."
			  << std::endl;
}

Karen::Karen()
{
}

void Karen::complain(std::string level)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};

    // 함수 포인터 문법 : Return_Type (Class_Name::* pointer_name)(Argument_List) = actual_pointer_of_function
	void (Karen::*funcs[4])(void) = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error,
	};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return;
		}
	}
    std::cerr << "Karen doesn't think of " << level << std::endl;
}

Karen::~Karen()
{
}