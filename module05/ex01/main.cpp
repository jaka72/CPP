/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 15:22:58 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
		try
	{
		Form form1("Form_A", 5, 3);
		std::cout << form1;

		Bureaucrat br1("Natasha", 9);
		
		for (int i = 0; i < 4; i++)
			br1.incr_grade();

		br1.signForm(form1); 
		br1.signForm(form1); 

		br1.incr_grade();	
		std::cout << br1;

		br1.signForm(form1);
		std::cout << form1;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	
	try
	{
		Form form1("Form_A", 0, 0);
		std::cout << form1;

		Bureaucrat br1("Natasha", 0);
		
		for (int i = 0; i < 4; i++)
			br1.incr_grade();
		
		br1.signForm(form1); 
		br1.signForm(form1); 

		br1.incr_grade();	
		std::cout << br1;

		br1.signForm(form1);
		std::cout << form1;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return 0;
}
