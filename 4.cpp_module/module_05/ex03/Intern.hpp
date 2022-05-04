/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:55:44 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 16:55:52 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern&);
	~Intern();

	Intern& operator=(const Intern&);

	Form* makeShrubberyCreation(const std::string& target) const;
	Form* makeRobotomyRequest(const std::string& target) const;
	Form* makePresidentialPardon(const std::string& target) const;
	Form* makeForm(const std::string& form, const std::string& target) const;
};

#endif
