/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 12:54:27 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::srand(std::time(NULL));
	{
		PresidentialPardonForm pre("tag");
		Bureaucrat bru("bru", 1);

		bru.signForm(pre);
		bru.executeForm(pre);
		std::cout << bru << std::endl;
		std::cout << pre << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		PresidentialPardonForm pre("tag");
		Bureaucrat bru("bru", 10);

		bru.signForm(pre);
		bru.executeForm(pre);
		std::cout << bru << std::endl;
		std::cout << pre << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		PresidentialPardonForm pre("tag");
		Bureaucrat bru("bru", 1);

		pre.beSigned(bru);
		pre.execute(bru);
		std::cout << bru << std::endl;
		std::cout << pre << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		PresidentialPardonForm pre("tag");
		Bureaucrat bru("bru", 1);

		bru.executeForm(pre);
		std::cout << bru << std::endl;
		std::cout << pre << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		RobotomyRequestForm rob("tag");
		Bureaucrat bru("bru", 1);

		bru.signForm(rob);
		bru.executeForm(rob);
		std::cout << bru << std::endl;
		std::cout << rob << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		RobotomyRequestForm rob("tag");
		Bureaucrat bru("bru", 1);

		bru.signForm(rob);
		bru.executeForm(rob);
		std::cout << bru << std::endl;
		std::cout << rob << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		RobotomyRequestForm rob("tag");
		Bureaucrat bru("bru", 1);

		bru.signForm(rob);
		bru.executeForm(rob);
		std::cout << bru << std::endl;
		std::cout << rob << std::endl;
	}
	std::cout << "------------" << std::endl;
	{
		ShrubberyCreationForm shr("tag");
		Bureaucrat bru("bru", 1);

		bru.signForm(shr);
		bru.executeForm(shr);
		std::cout << bru << std::endl;
		std::cout << shr << std::endl;
	}
	std::cout << "------------" << std::endl;
	system("leaks crat");
	return (0);
}
