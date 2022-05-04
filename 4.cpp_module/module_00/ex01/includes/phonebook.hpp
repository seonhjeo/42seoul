/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:12:09 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/14 17:03:54 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "content.hpp"

# define MAX 8

class PhoneBook
{
private:
	int		contentLen;
	int		lastEdited;
	Content	content[MAX];
public:
	PhoneBook();

	int	SetLastEdited();
	int	GetLastEdited();

	std::string GetPrintAbleStr(const std::string str);
	int	ShowIndex();

	int	Add();
	int	Search();
	int	Exit();

	~PhoneBook(){ }
};

#endif
