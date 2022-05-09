/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:56:22 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 00:16:24 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
			const std::string _target;
			ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm);
			ShrubberyCreationForm(void);
	public:
			ShrubberyCreationForm(const std::string target);
			virtual ~ShrubberyCreationForm();

			ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &shrubberyForm);

			void					execute(const Bureaucrat &bureaucrat) const;

};

#endif