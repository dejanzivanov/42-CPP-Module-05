/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:31:08 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/20 21:26:38 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{
	std::cout << CYION  << "[Bureaucrat] constructor has been called" << DEFAULT << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	std::cout << CYION << "[Bureaucrat] name constructor has been called" << DEFAULT << std::endl;

	if(grade < 1)
	{
		throw GradeTooHighException();
	}
	if(grade > 150)
	{
		throw GradeTooLowException();
	}

	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << CYION << "[Bureaucrat] copy constructor has been called" << DEFAULT << std::endl;
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{
	std::cout <<  RED << "[Bureaucrat] destructor has been called" << DEFAULT << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if(this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

const std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::increaseTheRank(void)
{
	if (_grade <= 1)
	{
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decreaseTheRank(void)
{
	if(_grade >= 150)
	{
		throw GradeTooLowException();
	}
	_grade++;
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", grade " << bureaucrat.getGrade();
	return ostream;
}