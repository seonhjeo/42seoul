/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:59:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/02/14 16:16:16 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_HPP
#define CONTENT_HPP

# include <string>

class Content
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Content(){ };

	const std::string GetFirstName();
	const std::string GetLastName();
	const std::string GetNickName();
	const std::string GetPhoneNumber();
	const std::string GetDarkestSecret();

	int SetFirstName(const char *_firstName);
	int SetLastName(const char *_lastName);
	int SetNickName(const char *_nickName);
	int SetPhoneNumber(const char *_phoneNumber);
	int SetDarkestSecret(const char *_darkestSecret);

	~Content(){ };
};

#endif
