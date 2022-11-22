/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:35:31 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:50:58 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class Bureaucrat;

// Required grade : sgin 145, exec 137
class ShrubberyCreationForm : public virtual Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ShrubberyCreationForm);

	// <target>_shrubbery라는 파일을 작성하고 현재 디렉토리에서 그 안에 ASCII 트리를 작성하십시오.
	void execute(Bureaucrat const &executor);

private:
	void makeTree();
};

#endif
