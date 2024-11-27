/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 12:29:25 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):_name("L'idiot du village"), _grade(150) {
	std::cout << "Recruitment of a new standard Bureaucrat named " << _name << "." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade):_name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "Recruitment of a new Bureaucrat named " << _name << "." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj):_name(obj._name), _grade(obj._grade) {
	*this = obj;
	std::cout << "Recruitment of a new Bureaucrat named " << _name << " has been cloned." << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj) {
	std::cout << "Recruitment of a new Bureaucrat named " << _name << " has been cloned." << std::endl;
	if (this != &obj)
		_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << _name << " is fired!" << std::endl;
}

std::string		Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::setGrade(int grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade == 1)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade == 150)
		throw GradeTooLowException();
	++_grade;
}

Bureaucrat::AlreadySignedException::AlreadySignedException(
	const std::string &bName, const std::string &fName):_bName(bName), _fName(fName) {
	_result = _bName + " couldn't sign " + _fName + " because already signed.";
}

Bureaucrat::GradeTooLowSignException::GradeTooLowSignException(
	const std::string &bName, const std::string &fName):_bName(bName), _fName(fName) {
	_result = std::string(_bName) + " couldn't sign " + std::string(_fName) + " because too low grade.";
}

Bureaucrat::AlreadySignedException::~AlreadySignedException(void) throw() {}

Bureaucrat::GradeTooLowSignException::~GradeTooLowSignException(void) throw() {}

const char *Bureaucrat::AlreadySignedException::what() const throw() {
	return (_result.c_str());
}

void	Bureaucrat::signForm(const Form &f) {
	if (f.getSigned() == 0 && f.getGradeSign() >= _grade)
		std::cout << _name << " signed " << f.getName() << std::endl;
	else if (f.getSigned() == 0 && f.getGradeSign() < _grade)
		throw GradeTooLowSignException(_name, f.getName());
	else
		throw AlreadySignedException(_name, f.getName());
}

const char* Bureaucrat::GradeTooLowSignException::what() const throw() {
	return (_result.c_str());
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The rank cannot be reduced!");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The rank cannot be incremented!");
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& a) {
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
    return (out);
}
