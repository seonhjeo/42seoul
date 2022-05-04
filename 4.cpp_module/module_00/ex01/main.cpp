/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:11:00 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/14 16:45:14 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/phonebook.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "---PHONEBOOK PROGRAM---" << std::endl << std::endl;
	while (1)
	{
		std::cout << "available command: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "input command: ";
		std::cin >> command;
		if (command.compare("ADD") == 0)
			phoneBook.Add();
		else if (command.compare("SEARCH") == 0)
			phoneBook.Search();
		else if (command.compare("EXIT") == 0)
			phoneBook.Exit();
		else
			std::cout << "we do not support that command: " << command << std::endl;
	}
	return (0);
}
