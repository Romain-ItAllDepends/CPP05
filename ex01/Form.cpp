/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:48:37 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/06 15:32:00 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void):_name("random"), _signed(0), _gradeSign(150), _gradeExecutive(149) {
	std::cout << "The standart form " << _name << " has been created!" << std::endl;
}

Form::Form(const std::string name):_name(name), _signed(0), _gradeSign(150), _gradeExecutive(149) {
	std::cout << "The form " << _name << " has been created!" << std::endl;
}

Form::Form(const Form &obj):_name(obj._name), _signed(obj._signed), _gradeSign(obj._gradeSign), _gradeExecutive(obj._gradeExecutive) {
	*this = obj;
	std::cout << "The form " << _name << " has been copied!" << std::endl;
}

Form &Form::operator=(const Form &obj) {
	std::cout << "The form " << _name << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		_signed = obj._signed;
	return (*this);
}

Form::~Form(void) {
	std::cout << "The form " << _name << " has been destroyed!" << std::endl;
}

const std::string	Form::getName(void) const {
	return (_name);
}

bool		Form::getSigned(void) const {
	return (_signed);
}

int	Form::getGradeSign(void) const {
	return (_gradeSign);
}

int	Form::getGradeExecutive(void) const {
	return (_gradeExecutive);
}

Form	Form::beSigned(const Bureaucrat &p) {
	if (_signed == 0 && p.getGrade() <= _gradeSign)
		_signed = 1;
	else if (_signed == 1)
		std::cout << "Already signed." << std::endl;
	else if (p.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Too high grade but I don't even know how you can get this shitty error.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Too low level to sign or execute the form.");
}

std::ostream &operator<<(std::ostream& out, const Form& a) {
	out << a.getName() << ", form signed grade " << a.getGradeSign();
	out << ", form execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
