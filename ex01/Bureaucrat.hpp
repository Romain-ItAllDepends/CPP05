/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 11:08:33 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "Form.hpp"
# include <iostream>
# include <exception>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &obj);
		~Bureaucrat(void);

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			setGrade(int grade);

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(const Form &f);

		class AlreadySignedException: public std::exception {
			private:
				std::string			_result;
				const std::string	_bName;
				const std::string	_fName;
			public:
				AlreadySignedException(const std::string &bName, const std::string &fName);
				virtual ~AlreadySignedException(void) throw();
				virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowSignException: public std::exception {
			private:
				std::string			_result;
				const std::string	_bName;
				const std::string	_fName;
			public:
				GradeTooLowSignException(const std::string &bName, const std::string &fName);
				virtual ~GradeTooLowSignException(void) throw();
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& a);

#endif