/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:38 by rgobet            #+#    #+#             */
/*   Updated: 2024/10/26 19:06:06 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iosbase>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const bool sign, const int gradeSign, const int gradeExec):AForm(name, sign, gradeSign, gradeExec) {
std::ofstream	outfile;
outfile.open(name + "_shrubbery".c_str(), ios_base::in);
outfile << "                        .__ ._       \\_. " << std::endl;
outfile << "                 _, _.  '  \\/   \\.-  /" << std::endl;
outfile << "                  \\/     .-_`   // |/     \\," << std::endl;
outfile << "                   \\.   '   \\`. ||  \\.-'  /" << std::endl;
outfile << "                  .-.`-(   _/\\ V/ \\//,-' >-'   ._," << std::endl;
outfile << "              .__/   `. \\.   ' J   ) ./  / __._/" << std::endl;
outfile << "        \\,      '   _/ \\  \\  | |  / /  .'-'.-' `._," << std::endl;
outfile << "   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\" << std::endl;
outfile << "    /    \\/        ._/`-.`  \\ .'.' .'---./__   '" << std::endl;
outfile << "          \\_. '   .---.  \\     /  /  ,   `  `" << std::endl;
outfile << "           `-.`__.'     `- \\  /   / _/-.---.__.- ." << std::endl;
outfile << "     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`" << std::endl;
outfile << "        / .-|(    x_.-'___  |   :' /    _..---_' " << std::endl;
outfile << "       /.\' /`-`._  `-,'   ` \'   I '_.--'__--..___.--._.-" << std::endl;
outfile << "   _.-\'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \\" << std::endl;
outfile << "       /   .---'-//.___. .-'       \\__ .--.  `    `.   '`-" << std::endl;
outfile << "   ` _/    _//     ./   _..   .'  `.    \\ \\    |_." << std::endl;
outfile << "          '    _..'  `.' . `.       )    | |\\  `" << std::endl;
outfile << "     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\" << std::endl;
outfile << "   ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`" << std::endl;
outfile << "        //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\." << std::endl;
outfile << "   .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '" << std::endl;
outfile << "     /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__" << std::endl;
outfile << "         /   `   _/|       J  /`     `-,,-----.`-." << std::endl;
outfile << "        '`      '          < `   f  I //        `\\_," << std::endl;
outfile << "                           J        I/\\_.        ./" << std::endl;
outfile << "                           I  .:    K  `          `" << std::endl;
outfile << "                          J         L" << std::endl;
outfile << "                          F  .-'    J" << std::endl;
outfile << "                          I  (.   . I _.-.._" << std::endl;
outfile << "                  _.---.J/      :'   L -'" << std::endl;
outfile << "                     _.-'_.)     ` `-.`---.,_." << std::endl;
outfile << "                .--""   .F' J) `.`L.__`-.___" << std::endl;
outfile << "                       Y ..Z     ))   `--'  `-" << std::endl;
outfile << "                         . /'    :/'" << std::endl;
}



ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("random", false, 145, 137) {
	std::cout << "The standart ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name):AForm(name, false, 145, 137) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj.getName(),
	obj.getGradeSign(), obj.getGradeSign(), obj.getGradeExecutive()) {
	*this = obj;
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj)
		this->setSigned(obj.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been destroyed!" << std::endl;
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& a) {
	out << a.getName() << ", ShrubberyCreationForm signed grade " << a.getGradeSign();
	out << ", ShrubberyCreationForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
