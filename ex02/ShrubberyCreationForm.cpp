/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:38 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/09 08:46:29 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const bool sign, const int gradeSign, const int gradeExec):AForm(name, sign, gradeSign, gradeExec) {
	std::cout << "The custom ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
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

void	ShrubberyCreationForm::executeFormIn(const Bureaucrat worker) const {
	std::ofstream	outfile;
	std::string		name = this->getName();

	const_cast<std::string&>(name).append("_shrubbery");
	std::cout << worker.getName() << " executed " << this->getName() << std::endl;
	outfile.open(name.c_str(), std::ofstream::app);
	outfile << "                        .__ ._       \\_.                                                            .__ ._       \\_." << std::endl;
	outfile << "                 _, _.  '  \\/   \\.-  /                                                      _, _.  '  \\/   \\.-  /" << std::endl;
	outfile << "                  \\/     .-_`   // |/     \\,                                                 \\/     .-_`   // |/     \\," << std::endl;
	outfile << "                   \\.   '   \\`. ||  \\.-'  /                                                  \\.   '   \\`. ||  \\.-'  /" << std::endl;
	outfile << "                  .-.`-(   _/\\ V/ \\//,-' >-'   ._,                                           .-.`-(   _/\\ V/ \\//,-' >-'   ._," << std::endl;
	outfile << "              .__/   `. \\.   ' J   ) ./  / __._/                                          .__/   `. \\.   ' J   ) ./  / __._/" << std::endl;
	outfile << "        \\,      '   _/ \\  \\  | |  / /  .'-'.-' `._,                               \\,      '   _/ \\  \\  | |  / /  .'-'.-' `._," << std::endl;
	outfile << "   \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\                          \\_.--.| \\_.      ' .___ `\\: | / .--'.-'\"     \\" << std::endl;
	outfile << "    /    \\/        ._/`-.`  \\ .'.' .'---./__   '                               /    \\/        ._/`-.`  \\ .'.' .'---./__   '" << std::endl;
	outfile << "          \\_. '   .---.  \\     /  /  ,   `  `                                        \\_. '   .---.  \\     /  /  ,   `  `" << std::endl;
	outfile << "           `-.`__.'     `- \\  /   / _/-.---.__.- .                                     `-.`__.'     `- \\  /   / _/-.---.__.- ." << std::endl;
	outfile << "     >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`                              >--.-\"\"'____.--\"`_     '   /.'..' \\   \\   _/`" << std::endl;
	outfile << "        / .-|(    x_.-'___  |   :' /    _..---_'                                        / .-|(    x_.-'___  |   :' /    _..---_' " << std::endl;
	outfile << "       /.\' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-                             /.' /`-`._  `-,'   ` '   I '_.--'__--..___.--._.-" << std::endl;
	outfile << "   _.-\'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \\                       _.-'      _.____./ .-.--\"\"-. .-\"    ' _..-.---'   \\" << std::endl;
	outfile << "       /   .---'-//.___. .-'       \\__ .--.  `    `.   '`-                          /   .---'-//.___. .-'       \\__ .--.  `    `.   '`-" << std::endl;
	outfile << "   ` _/    _//     ./   _..   .'  `.    \\ \\    |_.                             ` _/    _//     ./   _..   .'  `.    \\ \\    |_." << std::endl;
	outfile << "          '    _..'  `.' . `.       )    | |\\  `                                       '    _..'  `.' . `.       )    | |\\  `" << std::endl;
	outfile << "     \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\                               \\_..  .--'    ,\\ \\_/`  :    )  (`-. `.|`\\" << std::endl;
	outfile << "   ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`                        ._/ `\\'.--.,-((  `.`.__ |   _/   \\    |)  `--._/`" << std::endl;
	outfile << "        //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\.                            //'  //  _)   )/-._`.  (,-')  )  / \\_.    /\\." << std::endl;
	outfile << "   .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '                         .__./    //  '\\  |//    `.\\ '\\ (  (  <`   ._  '" << std::endl;
	outfile << "     /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__                            /   ..-\\ _    _/ \\_.  \\ `\\    \\_ `---.-'__" << std::endl;
	outfile << "         /   `   _/|       J  /`     `-,,-----.`-.                                  /   `   _/|       J  /`     `-,,-----.`-." << std::endl;
	outfile << "        '`      '          < `   f  I //        `\\_,                              '`      '          < `   f  I //        `\\_," << std::endl;
	outfile << "                           J        I/\\_.        ./                                                  J        I/\\_.        ./" << std::endl;
	outfile << "                           I  .:    K  `          `                                                   I  .:    K  `          `" << std::endl;
	outfile << "                          J         L                                                                J         L" << std::endl;
	outfile << "                          F  .-'    J                                                                F  .-'    J" << std::endl;
	outfile << "                          I  (.   . I _.-.._                                                         I  (.   . I _.-.._" << std::endl;
	outfile << "                  _.---.J/      :'   L -'                                                    _.---.J/      :'   L -'" << std::endl;
	outfile << "                     _.-'_.)     ` `-.`---.,_.                                                  _.-'_.)     ` `-.`---.,_." << std::endl;
	outfile << "                .--""   .F' J) `.`L.__`-.___                                               .--""   .F' J) `.`L.__`-.___" << std::endl;
	outfile << "                       Y ..Z     ))   `--'  `-                                                    Y ..Z     ))   `--'  `-" << std::endl;
	outfile << "                         . /'    :/'                                                                 . '    :'" << std::endl;
	outfile.close();
}

std::ostream &operator<<(std::ostream& out, const ShrubberyCreationForm& a) {
	out << a.getName() << ", ShrubberyCreationForm signed grade " << a.getGradeSign();
	out << ", ShrubberyCreationForm execute grade " << a.getGradeExecutive() << ".";
    return (out);
}
