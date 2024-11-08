/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/08 16:00:23 by rgobet           ###   ########.fr       */
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

void	PresidentialPardonForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

void	PresidentialPardonForm::executeFormIn(const Bureaucrat worker) {
	std::cout << worker.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& a) {
	out << a.getName() << ", PresidentialPardonForm signed grade " << a.getGradeSign();
	out << ", PresidentialPardonForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
