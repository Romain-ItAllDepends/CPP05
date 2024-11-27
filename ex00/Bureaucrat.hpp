/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:55 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/25 12:05:57 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

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

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream& out, const Bureaucrat& a);

#endif