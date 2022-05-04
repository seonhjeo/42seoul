/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:11:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 15:20:41 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequest", "", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: Form("RobotomyRequest", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: Form(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->Form::operator=(other);
	return (*this);
}

void RobotomyRequestForm::action() const
{
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << getTarget() << " has failed to make robotomized." << std::endl;
}
