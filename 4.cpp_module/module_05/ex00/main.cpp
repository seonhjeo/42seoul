/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 12:53:03 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Tom", 10);

	try
	{
		b.increaseGrade(9);
		std::cout << b << std::endl;
		b.increaseGrade(1);
		std::cout << b << std::endl;
		// 위에서 오류가 throw됨으로써 try문 내의 나머지 명령들은 건너뛰어짐.
		b.decreaseGrade(3);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		b.decreaseGrade(140);
		std::cout << b << std::endl;
		b.decreaseGrade(10);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	system("leaks crat");
	return 0;
}
