/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:27:27 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 13:09:36 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreation", "", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: Form("ShrubberyCreation", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: Form(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->Form::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::action() const
{
	std::string str = "ASCII TREE\n";

	std::ofstream ofs(getTarget() + "_shrubbery");
	if (!ofs)
	{
		throw std::runtime_error("The file could not be opened.");
	}
	ofs << str;
	if (ofs.fail())
	{
		throw std::runtime_error("Could not write to the file");
	}
}
