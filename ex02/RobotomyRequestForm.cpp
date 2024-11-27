/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:33 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 14:41:08 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

RobotomyRequestForm::RobotomyRequestForm(void):AForm("random", false, 72, 45), _target("default") {
	std::cout << "The standart RobotomyRequestForm " << this->getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", false, 72, 45), _target(target) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been created!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj):AForm(obj.getName(),
	obj.getSigned(), obj.getGradeSign(), obj.getGradeExecutive()), _target(obj._target) {
	*this = obj;
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been copied!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj) {
		this->setSigned(obj.getSigned());
		_target = obj._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "The RobotomyRequestForm " << this->getName() << " has been destroyed!" << std::endl;
}

const std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

void	RobotomyRequestForm::executeFormIn(void) const {
	std::cout << "Vrrrrrrrrrrrrrrrrrrrrr!" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() <<  " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}

std::ostream &operator<<(std::ostream& out, const RobotomyRequestForm& a) {
	out << a.getName() << ", RobotomyRequestForm signed grade " << a.getGradeSign();
	out << ", RobotomyRequestForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
