/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 12:34:42 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	Bureaucrat	obj("SIUUUUUUUUUUUUUUU", 150);
	Form		form("PER", 150, 149);

	try {
		// std::cout << obj << std::endl;
		// obj.setGrade(1);
		// obj.setGrade(150);
		// obj.decrementGrade();
		// obj.setGrade(1);
		// obj.incrementGrade();
		// std::cout << obj << std::endl;
		std::cout << "________________________\n" << std::endl;
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
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
