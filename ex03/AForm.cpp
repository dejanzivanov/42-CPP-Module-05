/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:27:00 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 00:01:25 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("denied"), _gradeSign(150), _gradeExecute(150), _signed(false)
{
	std::cout << GREEN  << "[Form] void constructor has been called" << DEFAULT << std::endl;
}

AForm::AForm(const std::string p_name, int p_gradeSign, int p_gradeExec):
_name(p_name), _gradeSign(p_gradeSign), _gradeExecute(p_gradeExec), _signed(false)
{
	std::cout << GREEN  << "[Form] name constructor has been called" << DEFAULT << std::endl;
	if(_gradeSign < 1 || _gradeExecute < 1)
	{
		throw GradeTooHighException();
	}
	if(_gradeSign > 150 || _gradeExecute > 150)
	{
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &form) : _name(form._name), _gradeSign(form._gradeSign), _gradeExecute(form._gradeExecute)
{
	std::cout << GREEN  << "[Form] copy constructor has been called" << DEFAULT << std::endl;
	*this = form;
}

AForm::~AForm(void)
{
	std::cout << RED << "[Form] destructor has been called" << DEFAULT << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
	std::cout << GREEN  << "[Form] overload assignment operator has been called" << DEFAULT << std::endl;
	if (this != &form)
	{
		_signed = form._signed;
	}

	return *this;
}

std::ostream &operator<<(std::ostream &outstream, const AForm &form)
{
	outstream << "[" << form.getName() << "]" << std::endl;
	outstream << "\t" << "signed : " << form.getSigned() << std::endl;
	outstream << "\t" << "grade needed to sign : " << form.getGradeSign() << std::endl;
	outstream << "\t" << "grade needed to execute : " << form.getGradeExec() << std::endl;
	return outstream;
}

const std::string AForm::getName(void) const
{
	return _name;
}

int	AForm::getGradeSign(void) const
{
	return _gradeSign;
}

int	AForm::getGradeExec(void) const
{
	return _gradeExecute;
}

bool AForm::getSigned(void) const
{
	return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
	{
		throw GradeTooLowException();
	}
	_signed = true;
}

void AForm::executeCheck(const Bureaucrat &bureaucrat) const
{
	if (!this->getSigned())
	{
		throw AForm::ExecuteNotSigned();
	}
	if(this->getGradeExec() < bureaucrat.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
}