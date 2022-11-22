/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:20 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:36:35 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
// Required grade : sgin 145, exec 137
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm","none", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : Form("ShrubberyCreationForm", _target, 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ShrubberyCreationForm)
{
	return (*this);
}

// <target>_shrubbery 파일을 작성하고 현재 디렉토리에서 그 안에 ASCII 트리를 작성하십시오.
void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	 std::cout << "[ ShrubberyCreationForm : execute ]" << std::endl;

	// 서명 안되어 있음
	if (getIsSigned() == false)
		throw IsnotSigned();
	// 실행 권한 부족
	if (getExecuteGrade() < executor.getGrade())
		throw LowGrade();
	makeTree();
}

void ShrubberyCreationForm::makeTree() {
	std::string filename = getTarget().append("_shrubbery");
	std::ifstream readFile;
	std::ofstream writeFile(filename);

	writeFile << "           {{ }{\n"
				 "          {{}}}{{\n"
				 "        {{}}{}}\n"
				 "           }}}}{\n"
				 "          {{}}}\n"
				 "         }{{}{}}\n"
				 "           {{}{}}\n"
				 "         }}{{}}\n"
				 "          {{}}{{\n"
				 "           \\  /\n"
				 "        .-''| |``-.\n"
				 "       '-._/_o_\\_.-'\n"
				 "        `._     _.'\n"
				 "         | :F_P: |\n"
				 "         `._    .'\n"
				 "            `--'";

	writeFile.close();
}
