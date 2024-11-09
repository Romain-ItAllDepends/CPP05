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
		AForm(const std::string name);
		AForm(const std::string name, const bool sign, const int gradeSign, const int gradeExec);
		AForm(const AForm &obj);
		AForm &operator=(const AForm &obj);
		virtual ~AForm(void);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecutive(void) const;

		void				setSigned(const bool sign);

		virtual void		beSigned(const Bureaucrat &p) = 0;
		void				execute(Bureaucrat const & executor) const;

		virtual void		executeFormIn(const Bureaucrat worker) const = 0;

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