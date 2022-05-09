/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:52:48 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/13 17:25:16 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iomanip>

static void	outputTitle(std::string title)
{
	std::string	toPrint;
	int	size = 60;
	int	n;

	toPrint = " " + title + " ";
	n = toPrint.size();
	if (n > size)
	{
		toPrint = toPrint.substr(0, size - 2);
		toPrint[size - 4] = '.';
		toPrint[size - 3] = ' ';
		n = toPrint.size();
	}
	std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
	std::cout << toPrint.substr(n / 2, n);
	std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

void	basicTest(void)
{
	Bureaucrat	deki("deki", 6);

	std::cout << deki << std::endl;
	deki.decreaseTheRank();
	std::cout << deki << std::endl;
	deki.increaseTheRank();
	deki.increaseTheRank();
	deki.increaseTheRank();
	deki.increaseTheRank();
	std::cout << deki << std::endl;
}

void lowExceptionTest(void)
{
	Bureaucrat deki("deki", 151);
}

void highExceptionTest(void)
{
	Bureaucrat deki("deki", 0);
}

void decrementGradeTest(void)
{
	Bureaucrat deki("deki", 2);
	deki.increaseTheRank();
	std::cout << deki << std::endl;
	deki.increaseTheRank();
}

void incrementGradeTest(void)
{
	Bureaucrat deki("deki", 140);
	deki.decreaseTheRank();
	std::cout << deki << std::endl;
	deki.decreaseTheRank();
}

int main(void)
{

	try
	{
		std::cout << std::endl;
		outputTitle("BASIC TEST");
		basicTest();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		outputTitle("LOW EXCEPTION TEST");
		lowExceptionTest();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		outputTitle("HIGH EXCEPTION TEST");
		highExceptionTest();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		outputTitle("DECREMENTAL TEST");
		decrementGradeTest();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << std::endl;
		outputTitle("INCREMENTAL TEST");
		incrementGradeTest();
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
	}

	return 0;
}