/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:58 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:35:15 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>
#include <random>

class Bureaucrat;

// Required grade : sgin 72, exec 45
class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &RobotomyRequestForm);

	// <target>_shrubbery라는 파일을 작성하고 현재 디렉토리에서 그 안에 ASCII 트리를 작성하십시오.
	void execute(Bureaucrat const &executor);

private:
	void Robotization();

};

#endif
