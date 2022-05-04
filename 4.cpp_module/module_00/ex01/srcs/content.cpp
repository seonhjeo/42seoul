/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:05:53 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/14 16:16:23 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/content.hpp"
#include <iostream>

const std::string Content::GetFirstName()
{
	return (firstName);
}
const std::string Content::GetLastName()
{
	return (lastName);
}
const std::string Content::GetNickName()
{
	return (nickName);
}
const std::string Content::GetPhoneNumber()
{
	return (phoneNumber);
}
const std::string Content::GetDarkestSecret()
{
	return (darkestSecret);
}

int Content::SetFirstName(const char *_firstName)
{
	firstName = std::string(_firstName);
	return (0);
}
int Content::SetLastName(const char *_lastName)
{
	lastName = std::string(_lastName);
	return (0);
}
int Content::SetNickName(const char *_nickName)
{
	nickName = std::string(_nickName);
	return (0);
}
int Content::SetPhoneNumber(const char *_phoneNumber)
{
	phoneNumber = std::string(_phoneNumber);;
	return (0);
}
int Content::SetDarkestSecret(const char *_darkestSecret)
{
	darkestSecret = std::string(_darkestSecret);
	return (0);
}
