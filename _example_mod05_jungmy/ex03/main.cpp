/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:50:47 by mjung             #+#    #+#             */
/*   Updated: 2021/12/17 17:57:14 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern intern1;
		Form *rtn;

		rtn = intern1.makeForm("RobotomyRequestForm", "mjung");
//		rtn = intern1.makeForm("wrongForm", "mjung");
		std::cout << rtn->getFormName() << std::endl;
		std::cout << rtn->getTarget() << std::endl;

		std::cout << *rtn << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}




	return (0);
}
