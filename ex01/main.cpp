/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:52:48 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/13 18:37:34 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Form visa("deki's visa", 10, 4);
	Bureaucrat karen("Karen", 11);

	std::cout << visa << std::endl;
	std::cout << karen << std::endl;

	karen.signForm(visa);
	karen.increaseTheRank();
	karen.signForm(visa);

	std::cout << std::endl << visa << std::endl;
}