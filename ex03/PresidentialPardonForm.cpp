/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:26 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 15:08:36 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("random", false, 25, 5), _target("default") {
	std::cout << "The standart PresidentialPardonForm " << this->getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm", false, 25, 5), _target(target) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been created!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):AForm(obj.getName(),
	obj.getSigned(), obj.getGradeSign(), obj.getGradeExecutive()), _target(obj._target) {
	*this = obj;
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been copied!" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj) {
		this->setSigned(obj.getSigned());
		_target = obj._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "The PresidentialPardonForm " << this->getName() << " has been destroyed!" << std::endl;
}

const std::string	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

void	PresidentialPardonForm::executeFormIn(void) const {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream& out, const PresidentialPardonForm& a) {
	out << a.getName() << ", signed grade " << a.getGradeSign();
	out << ", execute grade " << a.getGradeExecutive() << "." << std::endl;
	out << "Is signed ? " << a.getSigned() << std::endl;
	out << "Target: " << a.getTarget() << std::endl;
    return (out);
}
