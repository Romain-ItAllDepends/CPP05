/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:30 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 08:45:44 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);

		void	executeFormIn(const Bureaucrat worker) const;

		void	beSigned(const Bureaucrat &p);
};

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& a);

#endif
