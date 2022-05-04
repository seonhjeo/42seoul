/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:48:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/14 17:09:39 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/phonebook.hpp"

PhoneBook::PhoneBook()
{
	lastEdited = 0;
	contentLen = 0;
}

int	PhoneBook::SetLastEdited()
{
	lastEdited++;
	if (lastEdited == MAX)
		lastEdited = 0;
	contentLen++;
	if (contentLen > MAX)
		contentLen = MAX;
	return (0);
}

int	PhoneBook::GetLastEdited()
{
	return (lastEdited);
}

int	PhoneBook::Add()
{
	std::string	temp;

	std::cout << "you choose ADD command.." << std::endl;
	std::cout << "you will put data at line no." << lastEdited + 1 << std::endl;
	std::cout << "input firstname: ";
	std::cin >> temp;
	content[lastEdited].SetFirstName(temp.c_str());
	std::cout << "input lastname: ";
	std::cin >> temp;
	content[lastEdited].SetLastName(temp.c_str());
	std::cout << "input nickname: ";
	std::cin >> temp;
	content[lastEdited].SetNickName(temp.c_str());
	std::cout << "input phonenumber: ";
	std::cin >> temp;
	content[lastEdited].SetPhoneNumber(temp.c_str());
	std::cout << "input the DARKEST SECRET: ";
	std::cin >> temp;
	content[lastEdited].SetDarkestSecret(temp.c_str());
	std::cout << std::endl;
	SetLastEdited();
	return (0);
}

std::string PhoneBook::GetPrintAbleStr(const std::string str)
{
	std::string temp;

	if (str.length() <= 10)
		return (str);
	temp = str.substr(0, 8);
	temp.append(".");
	return (temp);
}

int	PhoneBook::ShowIndex()
{
	std::cout << std::endl << "--------------------" << std::endl;
	std::cout << "Print Index..." << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < contentLen; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << GetPrintAbleStr(content[i].GetFirstName());
		std::cout << "|" << std::setw(10) << GetPrintAbleStr(content[i].GetLastName());
		std::cout << "|" << std::setw(10) << GetPrintAbleStr(content[i].GetNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "--------------------" << std::endl;
	return (0);
}

int	PhoneBook::Search()
{
	int index;

	if(contentLen == 0)
	{
		std::cout << "There is no contents. ADD contents first." << std::endl;
		return (0);
	}
	else
	{
		ShowIndex();
		while (1)
		{
			std::cout << "input index for searching. input 0 for quit searching." << std::endl;
			std::cout << "index: ";
			std::cin >> index;
			if (index == 0)
				break ;
			else if (index < 0 || index > contentLen)
				std::cout << "index range over. input index from 0 to " << contentLen << std::endl;
			else
			{
				index -= 1;
				std::cout << "first name : " << content[index].GetFirstName() << std::endl;
				std::cout << "last name : " << content[index].GetLastName() << std::endl;
				std::cout << "nick name : " << content[index].GetNickName() << std::endl;
				std::cout << "phone number : " << content[index].GetPhoneNumber() << std::endl;
				std::cout << "DARKEST SECRET : " << content[index].GetDarkestSecret() << std::endl;
			}
		}
		std::cout << "quit searching..." << std::endl << std::endl;
	}
	return (0);
}

int PhoneBook::Exit()
{
	std::cout << "exit phonebook program" << std::endl;
	exit(0);
	return (0);
}
