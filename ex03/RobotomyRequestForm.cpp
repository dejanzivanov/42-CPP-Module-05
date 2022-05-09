/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:29:05 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 02:23:51 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy request", 72, 45), _target("error 404 target not found")
{
	std::cout << BLUE  << "[Robotomy Request Form] void constructor has been called" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy request", 72, 45), _target(target)
{
	std::cout << BLUE  << "[Robotomy Request Form] target constructor has been called" << DEFAULT << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomy) : AForm("Robotomy request", 72, 45), _target(robotomy._target)
{
	std::cout << BLUE  << "[Robotomy Request Form] copy constructor has been called" << DEFAULT << std::endl;
	*this = robotomy;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED  << "[Robotomy Request Form] copy constructor has been called" << DEFAULT << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomy)
{
	std::cout << BLUE  << "[Robotomy Request Form] overload assignment operator has been called" << DEFAULT << std::endl;
	(void)robotomy;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
	int robotomy;

	this->AForm::executeCheck(bureaucrat);
	std::cout << CYION << _target << " says Blackmail is such an ugly word. I prefer extortion. The ‘x’ makes it sound cool" << DEFAULT << std::endl;
	std::cout << CYION << "Initializing robotomy" << DEFAULT << std::endl;
	std::cout << CYION << "Bzzz rzzz Bzzzbzbzzzbzzz rzzz izzzrzzzbzzzz" << DEFAULT << std::endl;

	robotomy = rand() % 2;
	if(robotomy)
	{
		std::cout << GREEN << _target << " was robotomized." << DEFAULT << std::endl;
	}
	else
	{
		std::cout << GREEN << _target << " was not robotomized, procedure has failed, fugitive has run away." << DEFAULT << std::endl;
	}
}