/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:56:17 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 02:11:57 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			const std::string _target;
			PresidentialPardonForm(const PresidentialPardonForm &president);
			PresidentialPardonForm(void);
	public:
			PresidentialPardonForm(const std::string target);
			virtual ~PresidentialPardonForm();

			PresidentialPardonForm	&operator=(const PresidentialPardonForm &president);

			void					execute(const Bureaucrat &bureaucrat) const;

};

#endif