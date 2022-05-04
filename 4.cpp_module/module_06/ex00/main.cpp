/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:29:47 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/08 17:05:39 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "required one argument" << std::endl;
		return (1);
	}
	/*if (isNotValid(argv[1]))
	{
		std::cerr << "not valid input" << std::endl;
		return (1);
	}*/
	Convert convert(argv[1]);
	std::cout << convert;

	system("leaks convert");
	return (0);
}
