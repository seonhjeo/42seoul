/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:57:08 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/15 12:30:16 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Span.hpp"

int main(void)
{
	{
		std::cout << "============ Basic test ============" << std::endl;
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "============ Exception test ============" << std::endl;
		Span sp = Span(5);

		std::cout << "___ empty vector ___" << std::endl;
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		sp.addNumber(1);

		std::cout << "___ 1 element vector ___" << std::endl;
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			sp.longestSpan();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "============ push more than initial ============" << std::endl;
		try
		{
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			sp.addNumber(5);
			sp.addNumber(6);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "============ Iterator test ============ " << std::endl;

		Span sp(10000);

		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
		{
			vec.push_back(i + 1);
		}
		sp.addNumber(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "============ exception test ============ " << std::endl;

		Span sp1 = Span(5);

		sp1.addNumber(2);
		sp1.addNumber(3);
		sp1.addNumber(4);
		sp1.addNumber(5);
		sp1.addNumber(6);
		
		try
		{
			int n = sp1[7];
			std::cout << "sp17 : " << n << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			int n2 = sp1[-1];
			std::cout << "sp1-1 : " << n2<< std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
