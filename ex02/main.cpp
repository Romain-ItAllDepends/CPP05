/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 16:00:46 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	Bureaucrat	obj("SIUUUUUUUUUUUUUUU");
	PresidentialPardonForm		form("PER");

	try {
		std::cout << obj << std::endl;
		obj.decrementGrade();
		obj.setGrade(149);
		std::cout << obj << std::endl;
		obj.incrementGrade();
		std::cout << obj << std::endl;
		std::cout << "________________________\n" << std::endl;
		std::cout << form << std::endl;
		obj.signForm(form);
		form.beSigned(obj);
		std::cout << "Signed ? " << form.getSigned() << std::endl;
		obj.signForm(form);
	// } catch (const Form::GradeTooHighException& e) {
	// 	std::cerr << e.what() << std::endl;
	// } catch (const Form::GradeTooLowException& e) {
	// 	std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
