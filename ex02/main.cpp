/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 17:37:43 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	ShrubberyCreationForm		p("Full custom", false, 150, 149);
	Bureaucrat					b("Custom", 1);
	Bureaucrat					obj("SIUUUUUUUUUUUUUUU");
	PresidentialPardonForm		form("PER");
	RobotomyRequestForm			formR("ROB");
	ShrubberyCreationForm		formS("SHHHHHH");

	try {
		std::cout << obj << std::endl;
		obj.decrementGrade();
		obj.setGrade(149);
		std::cout << obj << std::endl;
		obj.incrementGrade();
		std::cout << obj << std::endl;
		std::cout << "________________________\n" << std::endl;
		std::cout << form << std::endl;
		// obj.signForm(form);
		// obj.signForm(formR);
		// obj.signForm(formS);
		p.beSigned(obj);
		std::cout << "Signed ? " << form.getSigned() << std::endl;
		obj.signForm(p);
		std::cout << "________________________\n" << std::endl;
		std::cout << p << std::endl;
		std::cout << b << std::endl;
		b.executeForm(p);
		p.execute(b);
		b.executeForm(form);
		form.execute(b);
	} catch (const AForm::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
