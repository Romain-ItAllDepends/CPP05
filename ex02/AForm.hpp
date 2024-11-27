/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:48:42 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/23 10:51:04 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecutive;
	public:
		AForm(void);
		AForm(const std::string &name, const int &gradeSign, const int &gradeExecutive);
		AForm(const std::string name, const bool sign, const int gradeSign, const int gradeExec);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecutive(void) const;

		void				setSigned(const bool sign);

		void			beSigned(const Bureaucrat &p);
		void			execute(Bureaucrat const & executor) const;
		virtual void	executeFormIn(void) const = 0;

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
		class NotSignedException: public std::exception {
			private:
				std::string			_result;
				const std::string	_bName;
				const std::string	_fName;
			public:
				NotSignedException(const std::string &bName, const std::string &fName);
				virtual ~NotSignedException(void) throw();
				virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, const AForm& a);

#endif