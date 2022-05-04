/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:57:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/16 13:38:02 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# define DEFAULT_GRADE 42

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _signGrade;
	const int _execGrade;
	Form() : _name(""), _signGrade(DEFAULT_GRADE), _execGrade(DEFAULT_GRADE){};

public:
	Form(std::string const &name, int signGrade, int execGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
	virtual ~Form();

	std::string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Permission denied: Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Permission denied: Grade too low");
		}
	};
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
