/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:31:05 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/13 17:29:56 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "color.h"
#include "Bureaucrat.hpp"
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &bureaucrat);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				increaseTheRank(void);
		void				decreaseTheRank(void);
		void				signForm(Form &form) const;


		class GradeTooHighException: public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Bureaucrat::exception : Grade is too high");
					}
		};

		class GradeTooLowException : public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Bueraucrat::exception : Grade is too low");
					}
		};
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif

