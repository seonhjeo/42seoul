/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 12:53:29 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat Tom("Tom", 10);

	try
	{
		Tom.increaseGrade(9);
		std::cout << Tom << std::endl;
		Tom.increaseGrade(1);
		std::cout << Tom << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form formC("c", 0, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form formA("a", 10, 10);
	Form formB("b", 10, 10);

	Tom.signForm(formA);
	Tom.decreaseGrade(10);
	Tom.signForm(formB);
	std::cout << formA << std::endl;
	std::cout << formB << std::endl;

	system("leaks crat");
	return 0;
}
