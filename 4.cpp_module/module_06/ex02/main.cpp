/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:59:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 17:17:14 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "this class is A from pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "this class is B from pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "this class is C from pointer" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "this class is A from referrer" << std::endl;
		return;
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "this class is B from referrer" << std::endl;
		return;
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "this class is C from referrer" << std::endl;
		return;
	}
	catch(...) {}

}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		Base *p = generate();
		Base &r = *p;
		identify(p);
		identify(r);
		delete(p);
		std::cout << "-------------------" << std::endl;
	}
	system("leaks identify");
	return (0);
}
