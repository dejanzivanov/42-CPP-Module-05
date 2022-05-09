/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:19:35 by dzivanov          #+#    #+#             */
/*   Updated: 2022/04/14 02:22:37 by dzivanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137), _target("unfamiliar")
{
	std::cout << GREEN  << "[Shrubbery Creation] void constructor has been called" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
	std::cout << GREEN  << "[Shrubbery Creation] target constructor has been called" << DEFAULT << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyForm)  : AForm("Shrubbery Creation", 145, 137), _target(shrubberyForm._target)
{
	std::cout << GREEN  << "[Shrubbery Creation] copy constructor has been called" << DEFAULT << std::endl;
	*this = shrubberyForm;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED  << "[Shrubbery Creation] copy constructor has been called" << DEFAULT << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyForm)
{
	std::cout << GREEN  << "[Shrubbery Creation] overload assignment operator has been called" << DEFAULT << std::endl;
	(void)shrubberyForm;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
	std::ofstream file;

	this->AForm::executeCheck(bureaucrat);
	file.open((_target + "_shrubber").c_str());
	if(file.good() == false)
	{
		throw OpeningFileFail();
	}

	file << "																," << std::endl;
	file << "													.__ ._       \\_." << std::endl;
	file << "											_, _.  '  \\/   \\.-  /" << std::endl;
	file << "											\\/     .-_`   // |/     \\," << std::endl;
	file << "							.-""""-.         \\.   '   \\`. ||  \\.-'  /" << std::endl;
	file << "							F        Y        .-.`-(   _/\\ V/ \\//,-' >-'   ._," << std::endl;
	file << "						F          Y   .__/   `. \\.   ' J   ) ./  / __._/" << std::endl;
	file << "						J         , I    '   _/ \\  \\  | |  / /  .'-'.-' `._," << std::endl;
	file << "				(       L   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     " << std::endl;
	file << "				\\ '\\    .  L   /    \\/        ._/`-.`  \\ .'.' .'---.__   '" << std::endl;
	file << "			\\__  '\\ ) \\._/   `-.__. ` \\_. '   .---.  \\     /  /  ,   `  `" << std::endl;
	file << "		--'  \\  ): // \\,            `-.`__.'     `- \\  /   / _/-.---.__.- ." << std::endl;
	file << "			_.-`.'/ /'\\_, ._     >--.-""'____.--\"\\_     '   /.'..' \\   \\   _/`" << std::endl;
	file << "		_ .---._\\ \'/ '__./__.-..  / .-|(    x_.-'___  |   :' /    _..---_' " << std::endl;
	file << "		.:' /`\\ `. `..'.--'\\      /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-" << std::endl;
	file << "			`  `. `\\/'/  _.   _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---   \\" << std::endl;
	file << "		-._ .--.\\ / /-./     /   .---'-//.___. .-'       \\__ .--.  `    `.     '`-" << std::endl;
	file << "		,--'/.-. ^.   .-.--.  ` _/    _//     ./   _..   .'  `.    \\ \\    |_." << std::endl;
	file << "			/' | >.   ' | \\._.-       '    _..'  `.' . `.       )    | |\\  `" << std::endl;
	file << "		./ \\ \'  ) c| /  \\     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\" << std::endl;
	file << "		\'  / ,-.  | ` ./`  ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`" << std::endl;
	file << "		______'\\   |  < __________  //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\. _____" << std::endl;
	file << "		a:f        |  |        .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '" << std::endl;
	file << "				>  |      _.  /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__" << std::endl;
	file << "				. /  `-   _.'        /   `   _/|       J  /`     `-,,-----.`-." << std::endl;
	file << "					'  .:'          '`      '          < `   f  I //        `­\\_," << std::endl;
	file << "					'                         \\.     J        I/\\_.        ./" << std::endl;
	file << "				__/                            `:     I  .:    K  `          `" << std::endl;
	file << "				\\/ )                            `,   J         L" << std::endl;
	file << "				)_(_                             .  F  .-'    J" << std::endl;
	file << "				/    `.                           .  I  (.   . I _.-.._" << std::endl;
	file << "		'    <'    \\ )                     _.---.J/      :'   L -'" << std::endl;
	file << "		.:.     \\. _.->/                        _.-'_.)     ` `-.`---.,_." << std::endl;
	file << "		:<        (    \\                    .--""   .F' J) `.`L.__`-.___" << std::endl;
	file << "		.:        |-'\\_.|                          Y ..Z     ))   `--'  `-" << std::endl;
	file << "		.         ) | > :                            . '    :'" << std::endl;
	file << "				/ ) L_J                            .x,." << std::endl;
	file << "				L_J .,                             .:<.," << std::endl;
	file << "				.'`   `                               :J.,`" << std::endl;
	file << "												. ;.+K,:." << std::endl;
	file << "													.,L+.," << std::endl;
	file.close();
}