/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:46:11 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/24 16:49:41 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
	Data num;

	num._value = 42;

	uintptr_t out = serialize(&num);

	Data *data = deserialize(out);

	std::cout << &num << std::endl;
	std::cout << out << std::endl;
	std::cout << data << std::endl;
	std::cout << data->_value << std::endl;

	system("leaks serialize");
	return (0);
}
