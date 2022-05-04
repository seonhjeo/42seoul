/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:21:23 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 16:15:21 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	virtual void action() const;

public:
	PresidentialPardonForm();
	explicit PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& a);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
};

#endif
