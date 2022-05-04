/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 12:55:11 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(std::time(NULL));
	Bureaucrat bru("bru", 1);

	{
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			bru.signForm(*rrf);
			bru.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << "--------------------" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			bru.signForm(*rrf);
			bru.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << "--------------------" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			bru.signForm(*rrf);
			bru.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << "--------------------" << std::endl;
	{
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("a", "Bender");
		if (rrf)
		{
			bru.signForm(*rrf);
			bru.executeForm(*rrf);
			delete rrf;
		}
	}
	std::cout << "--------------------" << std::endl;
	system("leaks crat");
	return (0);
}
