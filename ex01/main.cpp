/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/06 13:57:39 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat	obj("SIUUUUUUUUUUUUUUU");
	Form		form("PER");

	try {
		std::cout << obj << std::endl;
		obj.setGrade(1);
		// obj.setGrade(150);
		// obj.decrementGrade();
		// obj.setGrade(1);
		// obj.incrementGrade();
		std::cout << obj << std::endl;
		std::cout << "________________________\n" << std::endl;
		std::cout << form << std::endl;
		obj.signForm(form);
		form.beSigned(obj);
		std::cout << "Signed ? " << form.getSigned() << std::endl;
		obj.signForm(form);
	} catch (const Form::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Form::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
