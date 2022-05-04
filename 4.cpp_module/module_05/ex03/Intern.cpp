/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:02:22 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 17:06:56 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern::~Intern() {}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

Form* Intern::makeShrubberyCreation(const std::string& target) const
{
	Form* form = new ShrubberyCreationForm(target);
	return form;
}

Form* Intern::makeRobotomyRequest(const std::string& target) const
{
	Form* form = new RobotomyRequestForm(target);
	return form;
}

Form* Intern::makePresidentialPardon(const std::string& target) const
{
	Form* form = new PresidentialPardonForm(target);
	return form;
}

Form* Intern::makeForm(const std::string& form, const std::string& target) const
{
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*funcList[3])(const std::string&) const = \
		{&Intern::makeShrubberyCreation, \
		&Intern::makeRobotomyRequest, \
		&Intern::makePresidentialPardon};

	Form* ret = NULL;
	for (int i = 0; i < 3; ++i)
	{
		if (form == formList[i])
		{
			ret = (this->*funcList[i])(target);
			return ret;
		}
	}
	std::cerr << "There is no form with that name: " << form << std::endl;
	return NULL;
}
