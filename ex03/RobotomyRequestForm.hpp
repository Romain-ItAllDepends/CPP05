/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:36 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/08 15:49:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
		~RobotomyRequestForm(void);

		void	executeFormIn(const Bureaucrat worker);

		void	beSigned(const Bureaucrat &p);
};

std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& a);

#endif