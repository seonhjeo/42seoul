/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:30:19 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/14 12:43:46 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"
#include <string>

int main()
{
	{
		std::string array[3] = {"string1", "string2", "string3"};
		iter(array, 3, sample_func<std::string>);
	}
	std::cout << "---------" << std::endl;
	{
		std::string array[3] = {"string1", "string2", "string3"};
		iter(array, 3, sample_func2<std::string>);
	}
	std::cout << "---------" << std::endl;
	{
		const int array[3] = {2, 1, 100};
		iter(array, 3, sample_func<const int>);
	}
	std::cout << "---------" << std::endl;
	{
		const double array[3] = {2.3, 1.7, 42.42};
		iter(array, 3, sample_func<const double>);
	}
	std::cout << "---------" << std::endl;
	return (0);
}
