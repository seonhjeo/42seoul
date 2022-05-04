/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:15:24 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 16:16:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardon", "", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form("PresidentialPardon", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& a)
	: Form(a) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&)
{
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
