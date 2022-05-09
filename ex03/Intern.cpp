/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:15:50 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/20 20:56:49 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << GREEN  << "[Intern] constructor has been called" << DEFAULT << std::endl;
	return ;
}

Intern::Intern(const Intern &intern)
{
	std::cout << GREEN << "[Intern] copy constructor has been called" << DEFAULT << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::~Intern()
{
	std::cout <<  RED << "[Intern] destructor has been called" << DEFAULT << std::endl;
	return ;
}

static AForm *shrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm *presidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *robotomyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static const std::string toLowerString(const std::string string)
{
	std::string result;
	
	for (unsigned int i = 0; i < string.size(); i++)
	{
		result += tolower(string[i]);
	}
	return (result);
}

static int getFormNumber(const std::string formName)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int	choosen = -1;

	for(int i = 0; i < 3; i++)
	{
		if(toLowerString(formName) == formNames[i])
		{
			choosen = i;
			break;
		}	
	}
	return choosen;
}

AForm *Intern::makeForm(const std::string formName, const std::string target) const
{
	constructorPointer	funCreations[3] = {&shrubberyForm, &robotomyForm, &presidentialForm};
	int				choosen;
	AForm			*formPtr = NULL;

	choosen = getFormNumber(formName);
	std::cout << YELLOW << "Intern" << DEFAULT;
	if (choosen >= 0)
	{
		formPtr = funCreations[choosen](target);
		std::cout << " creates " << GREEN << formPtr->getName() << DEFAULT << " formular" << std::endl;
	}
	else
		std::cout << " cannot create " << GREEN << formName << DEFAULT << " because " << BLUE << "it's unknown" << DEFAULT << std::endl;
	return (formPtr);
}