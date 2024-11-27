/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 15:15:55 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdlib.h>
#include <time.h>

int	main(void) {
	PresidentialPardonForm		p("redone p");
	RobotomyRequestForm			r("redone r");
	ShrubberyCreationForm		s("redone s");
	Bureaucrat					b("Custom", 1);
	RobotomyRequestForm			formR("ROB");
	RobotomyRequestForm			formRi("ROBY");
	ShrubberyCreationForm		formS("SHHHHHH");
	Bureaucrat					obj("SIUUUUUUUUUUUUUUUU", 150);
	PresidentialPardonForm		form("PER");
	Intern						jack;
	// AForm						form("PER", 150, 149);

	srand(time(NULL));	
	try {
		// std::cout << obj << std::endl;
		// obj.setGrade(1);
		// obj.setGrade(150);
		// obj.decrementGrade();
		// obj.setGrade(1);
		// obj.incrementGrade();
		// std::cout << obj << std::endl;
		// std::cout << "________________________\n" << std::endl;
		// std::cout << form << std::endl;
		// obj.signForm(form);
		// form.beSigned(obj);
		// form.beSigned(obj);
		// obj.signForm(form);
		// std::cout << form << std::endl;
		// form.setSigned(0);
		// obj.setGrade(150);
		// std::cout << form << std::endl;
		// form.beSigned(obj);
		// std::cout << form << std::endl;
		// obj.signForm(form); // set gradeSign lower than 150 for this test
		// form.beSigned(obj);
		// std::cout << form << std::endl;
		// std::cout << "________________________\n" << std::endl;
		// std::cout << p << std::endl; // Custom ShrubberyCreationForm
		// std::cout << b << std::endl;
		// p.beSigned(b); // Don't comment this one
		// // r.beSigned(b); // Sign all and exec
		// // s.beSigned(b);
		// // b.executeForm(p);
		// // b.executeForm(r);
		// // b.executeForm(s);
		// b.setGrade(150);
		// std::cout << b << std::endl; // A verif
		// // b.executeForm(form); // Form not signed is ok
		// // b.executeForm(p); // Form signed but too low grade
		// // p.execute(b); // Too low level catch
		// b.setGrade(1);
		// formR.beSigned(b);
		// b.executeForm(formR); // ROB (robotomy)
		// // form.execute(b); // Not signed
		// form.beSigned(b); // PER (president)
		// b.executeForm(form);
		std::cout << "________________________\n" << std::endl;
		delete jack.makeForm("robotomy request", "Jack");
		delete jack.makeForm("shrubbery creation", "Jean");
		delete jack.makeForm("presidential pardon", "Jacko");
		jack.makeForm("robotomy reques", "Raté");
		std::cout << "________________________\n" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
