/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:54:53 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/22 15:17:50 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	virtual void action() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
};

#endif
