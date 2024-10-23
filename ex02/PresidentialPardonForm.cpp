/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 15:38:03 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("random", false, 25, 5) {
	std::cout << "The standart PresidentialPardonForm " << this->getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string name):AForm(name, false, 25, 5) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):AForm(obj.getName(),
	obj.getSigned(), obj.getGradeSign(), obj.getGradeExecutive()) {
	*this = obj;
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been copied!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		this->setSigned(obj.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been destroyed!" << std::endl;
}

void	AForm::beSigned(const Bureaucrat &p) {
	if (_signed == false && p.getGrade() <= _gradeSign)
		_signed = true;
	else if (p.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() {
	return ("Too high grade but I don't even know how you can get this shitty error.");
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return ("Too low level to sign or execute the PresidentialPardonForm.");
}

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& a) {
	out << a.getName() << ", PresidentialPardonForm signed grade " << a.getGradeSign();
	out << ", PresidentialPardonForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
