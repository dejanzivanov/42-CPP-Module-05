/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:56:19 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 01:28:53 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <ctime>
# include <cstdlib>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			const std::string _target;
			RobotomyRequestForm(const RobotomyRequestForm &robotomy);
			RobotomyRequestForm(void);
	public:
			RobotomyRequestForm(const std::string target);
			virtual ~RobotomyRequestForm();

			RobotomyRequestForm	&operator=(const RobotomyRequestForm &robotomy);

			void					execute(const Bureaucrat &bureaucrat) const;

};

#endif