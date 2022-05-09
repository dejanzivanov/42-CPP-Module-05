/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:27:03 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 00:01:59 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
			const std::string	_name;
			const int			_gradeSign;
			const int			_gradeExecute;
			bool				_signed;

	public:
			AForm(void);
			AForm(const std::string name, int gradeSign, int gradeExecute);
			AForm(const AForm &form);
			virtual ~AForm();
			AForm &operator=(const AForm &form);

			const std::string 	getName(void) const;
			int					getGradeSign(void) const;
			int					getGradeExec(void) const;
			bool				getSigned(void) const;
			void				beSigned(const Bureaucrat &bureaucrat);
			virtual void		execute(const Bureaucrat &bureaucrat) const = 0;
			void				executeCheck(const Bureaucrat &bureaucrat) const;

		class GradeTooHighException: public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Grade is too high");
					}
		};

		class GradeTooLowException : public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Grade is too low");
					}
		};

		class ExecuteNotSigned : public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Form is not signed");
					}
		};

		class OpeningFileFail : public std::exception
		{
			public:
					virtual const char *what() const throw()
					{
						return ("Form can not be opened");
					}
		};
};

std::ostream  &operator<<(std::ostream &outstream, const AForm &form);

#endif