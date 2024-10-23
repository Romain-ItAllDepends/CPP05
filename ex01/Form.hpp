/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:48:42 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 09:33:14 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecutive;
	public:
		Form(void);
		Form(const std::string name);
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		~Form(void);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExecutive(void) const;

		Form	beSigned(const Bureaucrat &p);

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, const Form& a);

#endif