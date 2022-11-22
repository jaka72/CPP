/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:52 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:34:53 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentPardonForm.hpp"

PresidentPardonForm::PresidentPardonForm() : Form::Form("PresidentPardonForm", "none", 25, 5)
{
}

PresidentPardonForm::PresidentPardonForm(std::string _target) : Form::Form("PresidentPardonForm", _target, 25, 5)
{
}

PresidentPardonForm::~PresidentPardonForm()
{

}

PresidentPardonForm::PresidentPardonForm(const PresidentPardonForm &PresidentPardonForm)
{

}

PresidentPardonForm &PresidentPardonForm::operator=(const PresidentPardonForm &ShrubberyCreationForm)
{
	return (*this);
}

// Zafod Beeblebrox가 <target>을 사면했다고 알려줍니다.
void PresidentPardonForm::execute(Bureaucrat const &executor)
{
	std::cout << "[ PresidentPardonForm : execute]" << std::endl;
	// 서명 안되어 있음
	if (getIsSigned() == false)
		throw IsnotSigned();
	// 실행 권한 부족
	if (getExecuteGrade() < executor.getGrade())
		throw LowGrade();
	pardon();
}

void PresidentPardonForm::pardon() {
	std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
