/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 09:01:10 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
	Intern						jack;

	try {
		// Each test is comment to avoid the previous test to change the current test

		// std::cout << obj << std::endl;
		// obj.setGrade(150);
		// obj.decrementGrade();
		// // obj.setGrade(1);
		// // obj.incrementGrade();
		// std::cout << obj << std::endl;
		std::cout << "________________________\n" << std::endl;
		// std::cout << form << std::endl;
		// obj.signForm(form);
		// form.beSigned(obj);
		// form.beSigned(obj);
		// obj.signForm(form);
		// std::cout << "Signed ? " << form.getSigned() << std::endl;
		// form.setSigned(0);
		// obj.setGrade(150);
		// std::cout << "Signed ? " << form.getSigned() << std::endl;
		// form.beSigned(obj);
		// std::cout << "Signed ? " << form.getSigned() << std::endl;
		// obj.signForm(form); // set gradeSign lower than 150 for this test
		// form.beSigned(obj);
		// std::cout << "Signed ? " << form.getSigned() << std::endl;
		std::cout << "________________________\n" << std::endl;
		// std::cout << p << std::endl; // Custom ShrubberyCreationForm
		// std::cout << b << std::endl;
		// p.beSigned(b);
		// b.executeForm(p);
		// b.setGrade(150);
		// std::cout << b << std::endl;
		// b.executeForm(form); // Form not signed is ok
		// b.executeForm(p); // Form signed but too low grade
		// // p.execute(b); // Too low level catch
		// b.setGrade(1);
		// formR.beSigned(b);
		// b.executeForm(formR); // ROB (robotomy)
		// form.execute(b); // Not signed
		// form.beSigned(b); // PER (president)
		// b.executeForm(form);
		std::cout << "________________________\n" << std::endl;
		std::cout << jack.makeForm("robotomy request", "Jack") << std::endl;
		std::cout << jack.makeForm("shrubbery creation", "Jean") << std::endl;
		std::cout << jack.makeForm("presidential pardon", "Jacko") << std::endl;
		std::cout << jack.makeForm("robotomy reques", "Raté") << std::endl;
		std::cout << "________________________\n" << std::endl;
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
