/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:49:38 by rgobet            #+#    #+#             */
/*   Updated: 2024/11/27 15:08:52 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("random", false, 145, 137), _target("default") {
	std::cout << "The standart ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj):AForm(obj.getName(),
	obj.getGradeSign(), obj.getGradeSign(), obj.getGradeExecutive()), _target(obj._target) {
	*this = obj;
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied!" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been copied by assignment!" << std::endl;
	if (this != &obj) {
		this->setSigned(obj.getSigned());
		_target = obj._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "The ShrubberyCreationForm " << this->getName() << " has been destroyed!" << std::endl;
}

const std::string	ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat &p) {
	if (this->getSigned() == false && p.getGrade() <= this->getGradeSign())
		this->setSigned(true);
	else if (p.getGrade() > this->getSigned())
		throw AForm::GradeTooLowException();
}

void	ShrubberyCreationForm::executeFormIn(void) const {
	std::ofstream	outfile;
	std::string		name = this->getTarget();

	const_cast<std::string&>(name).append("_shrubbery");
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
	out << a.getName() << ", signed grade " << a.getGradeSign();
	out << ", execute grade " << a.getGradeExecutive() << "." << std::endl;
	out << "Is signed ? " << a.getSigned() << std::endl;
	out << "Target: " << a.getTarget() << std::endl;
    return (out);
}
