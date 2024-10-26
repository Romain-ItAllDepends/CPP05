/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:38 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/26 16:12:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const bool sign, const int gradeSign, const int gradeExec):AForm(name, sign, gradeSign, gradeExec) {
	
}



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

void	ShrubberyCreationForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& a) {
	out << a.getName() << ", ShrubberyCreationForm signed grade " << a.getGradeSign();
	out << ", ShrubberyCreationForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
