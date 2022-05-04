/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:26:29 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/17 11:22:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "string address : " << &brain << std::endl;
	std::cout << "string address by ptr : " << stringPTR << std::endl;
	std::cout << "string address by reference : " << &stringREF << std::endl;
    
	std::cout << "===============================" << std::endl;
    
	std::cout << "string by ptr : " << *stringPTR << std::endl;
	std::cout << "string by reference : " << stringREF << std::endl;
}