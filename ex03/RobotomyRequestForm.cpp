/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:33 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/26 16:12:21 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("random", false, 72, 45) {
	std::cout << "The standart RobotomyRequestForm " << this->getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name):AForm(name, false, 72, 45) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):AForm(obj.getName(),
	obj.getSigned(), obj.getGradeSign(), obj.getGradeExecutive()) {
	*this = obj;
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been copied!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		this->setSigned(obj.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been destroyed!" << std::endl;
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& a) {
	out << a.getName() << ", RobotomyRequestForm signed grade " << a.getGradeSign();
	out << ", RobotomyRequestForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
