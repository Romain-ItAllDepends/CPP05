/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:48:37 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 09:12:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):_name("random"), _signed(false), _gradeSign(150), _gradeExecutive(149) {
	std::cout << "The standart AForm " << _name << " has been created!" << std::endl;
}

AForm::AForm(const std::string &name, const int &gradeSign, const int &gradeExecutive):_name(name), _signed(0), _gradeSign(gradeSign), _gradeExecutive(gradeExecutive) {
	if (gradeSign > 150 || gradeExecutive > 150)
		throw GradeTooLowException();
	if (gradeSign < 1 || gradeExecutive < 1)
		throw GradeTooHighException();
	std::cout << "The AForm " << _name << " has been created!" << std::endl;
}

AForm::AForm(const std::string name, const bool sign, const int gradeSign,
	const int gradeExec):_name(name), _signed(sign), _gradeSign(gradeSign),
	_gradeExecutive(gradeExec) {
	std::cout << "The full AForm " << _name << " has been created!" << std::endl;
}

AForm::AForm(const AForm &obj):_name(obj._name), _signed(obj._signed), _gradeSign(obj._gradeSign), _gradeExecutive(obj._gradeExecutive) {
	*this = obj;
	std::cout << "The AForm " << _name << " has been copied!" << std::endl;
}

AForm &AForm::operator=(const AForm &obj) {
	std::cout << "The AForm " << _name << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		_signed = obj._signed;
	return (*this);
}

AForm::~AForm(void) {
	std::cout << "The AForm " << _name << " has been destroyed!" << std::endl;
}

AForm::AlreadySignedException::AlreadySignedException(
	const std::string &bName, const std::string &fName):_bName(bName), _fName(fName) {
	_result = _bName + " couldn't sign " + _fName + " because already signed.";
}

AForm::NotSignedException::NotSignedException(
	const std::string &bName, const std::string &fName):_bName(bName), _fName(fName) {
	_result = std::string(_bName) + " couldn't execute " + std::string(_fName) + " because form is not signed.";
}

AForm::NotSignedException::~NotSignedException(void) throw() {}

AForm::AlreadySignedException::~AlreadySignedException(void) throw() {}

const char *AForm::AlreadySignedException::what() const throw() {
	return (_result.c_str());
}

const char* AForm::NotSignedException::what() const throw() {
	return (_result.c_str());
}

const std::string	AForm::getName(void) const {
	return (_name);
}

bool		AForm::getSigned(void) const {
	return (_signed);
}

int	AForm::getGradeSign(void) const {
	return (_gradeSign);
}

int	AForm::getGradeExecutive(void) const {
	return (_gradeExecutive);
}

void	AForm::setSigned(const bool sign) {
	_signed = sign;
}

void	AForm::beSigned(const Bureaucrat &p) {
	if (_signed == 0 && p.getGrade() <= _gradeSign)
		_signed = 1;
	else if (_signed == 1)
		throw AForm::AlreadySignedException(p.getName(), _name);
	else if (p.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > _gradeExecutive)
		throw AForm::GradeTooLowException();
	else if (_signed == false)
		throw AForm::NotSignedException(executor.getName(), _name);
	else
		std::cout << "The Form " << _name << " has been execute!" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Too high grade but this error can't be trigger.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Too low level to sign or execute the AForm.");
}

std::ostream &operator<<(std::ostream& out, const AForm& a) {
	out << a.getName() << ", AForm signed grade " << a.getGradeSign();
	out << ", AForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
