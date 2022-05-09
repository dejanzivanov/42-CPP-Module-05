/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:57:40 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 02:24:11 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidental Pardon", 25, 5), _target("boss")
{
	std::cout << ORANGE  << "[Presidential Pardon Form] void constructor has been called" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Robotomy request", 25, 2), _target(target)
{
	std::cout << ORANGE  << "[Presidential Pardon Form] target constructor has been called" << DEFAULT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &president) : AForm("Robotomy request", 25, 2), _target(president._target)
{
	std::cout << ORANGE  << "[Presidential Pardon Form] copy constructor has been called" << DEFAULT << std::endl;
	*this = president;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED  << "[Presidential Pardon Form] copy constructor has been called" << DEFAULT << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &president)
{
	std::cout << ORANGE  << "[Presidential Pardon Form] overload assignment operator has been called" << DEFAULT << std::endl;
	(void)president;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	this->AForm::executeCheck(bureaucrat);
	std::cout << GREEN << _target << DEFAULT << " has been pardoned by Zafor Beeblebrox" << std::endl;
}