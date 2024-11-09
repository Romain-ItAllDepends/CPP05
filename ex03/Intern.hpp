/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:11:18 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 10:02:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
# include <iostream>

# define PresidentPardon 0
# define RobotomyRequest 1
# define ShrubberyCreation 2

class AForm;

class Intern {
	public:
		Intern(void);
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern(void);

		AForm *makeForm(std::string name, std::string target);
};

#endif