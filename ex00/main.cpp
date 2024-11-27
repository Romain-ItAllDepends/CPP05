/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:45 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/25 14:42:51 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	obj("SIUUUUUUUUUUUUUUU", 150);

	try {
		std::cout << obj << std::endl;
		obj.setGrade(150);
		obj.decrementGrade();
		// obj.setGrade(1);
		// obj.incrementGrade();
		std::cout << obj << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
