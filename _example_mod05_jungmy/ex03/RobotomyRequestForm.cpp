/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:36:02 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:36:08 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form::Form("RobotomyRequestForm", "none", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : Form::Form("RobotomyRequestForm", _target, 72, 45)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RobotomyRequestForm)
{
	return (*this);
}

// 드릴 소리를 내며 <target>이 50%의 확률로 성공적으로 로봇화되었다고 알려주십시오. 그렇지 않으면 실패라고 알려주십시오.
void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	std::cout << "[ RobotomyRequestForm : execute]" << std::endl;
	// 서명 안되어 있음
	if (getIsSigned() == false)
		throw IsnotSigned();
	// 실행 권한 부족
	if (getExecuteGrade() < executor.getGrade())
		throw LowGrade();
	Robotization();
}

void RobotomyRequestForm::Robotization()
{
	// 시드값을 얻기 위한 random_device 생성.
	std::random_device rd;
	// random_device 를 통해 난수 생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	std::uniform_int_distribution<int> dis(0, 1);

	std::cout << "Drrrrrrrr... Drrrrrr... Drr!" << std::endl;
	if (dis(gen) == 0)
	{
		std::cout << Form::getTarget() << " has become a robot." << std::endl;
	}
	else
	{
		std::cout << "Fail.... :(" << std::endl;
	}
}
