/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:08 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/08 08:52:01 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
	std::cout << "Recruitment of a new standard Intern." << std::endl;
}

Intern::Intern(const Intern &obj) {
	std::cout << "Recruitment of a new clone of an Intern." << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj) {
	std::cout << "Recruitment of a new clone of an Intern." << std::endl;
	(void)obj;
	return (*this);
}

Intern::~Intern(void) {
	std::cout << "All my condolences, this Intern is dead." << std::endl;
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	int			i;
	std::string	types[3];

	i = 0;
	types[0] = "presidential pardon";
	types[1] = "robotomy request";
	types[2] = "shrubbery creation";
	while (i < 4 && types[i] != name)
		i++;
	switch (i) {
		case PresidentPardon:
			std::cout << "Intern creates" << target << std::endl;
			return (new PresidentialPardonForm(target));
		case RobotomyRequest:
			std::cout << "Intern creates" << target << std::endl;
			return (new RobotomyRequestForm(target));
		case ShrubberyCreation:
			std::cout << "Intern creates" << target << std::endl;
			return (new ShrubberyCreationForm(target));
	}
	std::cerr << "Doesn't exist." << std::endl;
	return (NULL);
}