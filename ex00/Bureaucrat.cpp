/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/25 14:04:44 by rgobet           ###   ########.fr       */
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
