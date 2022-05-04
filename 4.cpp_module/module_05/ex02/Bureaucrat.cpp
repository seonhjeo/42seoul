/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:40:51 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 16:18:20 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	this->_grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade(int amount)
{
	if (this->_grade - amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade - amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade -= amount;
}

void Bureaucrat::decreaseGrade(int amount)
{
	if (this->_grade + amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += amount;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signs " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " cannot sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " could not execute " << \
					 form.getName() << " reason: " << \
					 e.what() << std::endl;
		return;
	}
	std::cout << _name << " executes " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
