/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:11:52 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 16:17:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

class Bureaucrat
{
private:
	std::string _name;
	int _grade;

	Bureaucrat() : _name(""){};
public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void increaseGrade(int amount);
	void decreaseGrade(int amount);

	void signForm(Form &form);
	void executeForm(Form const &form);

	// execption 클래스를 상속받는 예외처리 클래스들
	// 본 클래스 내부에 자리잡음으로써 Bureaucrat 클래스는 자가적인 오류 검출 능력을 지니게 되고
	// 이는 코드의 안정성 향상을 불러온다.
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
};

// << 연산자(비트연산자)에 오버라이딩 함으로써 해당 클래스의 출력 형식을 재정의
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
