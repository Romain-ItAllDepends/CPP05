/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:38 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 15:55:07 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("random", false, 145, 137) {
	std::cout << "The standart ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name):AForm(name, false, 145, 137) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj.getName(),
	obj.getGradeSign(), obj.getGradeSign(), obj.getGradeExecutive()) {
	*this = obj;
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		this->setSigned(obj.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been destroyed!" << std::endl;
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return ("Too high grade but I don't even know how you can get this shitty error.");
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Too low level to sign or execute the ShrubberyCreationForm.");
}

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& a) {
	out << a.getName() << ", ShrubberyCreationForm signed grade " << a.getGradeSign();
	out << ", ShrubberyCreationForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
