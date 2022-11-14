/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 15:24:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{

	// {
	// 	Bureaucrat br1;
	// 	std::cout << br1;

    //     Bureaucrat br2(br1);
	// 	// std::cout << br1;
	// 	std::cout << br2;

    //     Bureaucrat br3 = br2;
	// 	std::cout << br3;

    //     Bureaucrat br4;
    //     br4 = br3;
	// 	std::cout << br4;
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		
	// {
	// 	Bureaucrat br1("Br1", 0);

	// 	br1.incr_grade();
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	
	// {
	// 	Bureaucrat br1("Br1", 1);

	// 	br1.incr_grade();
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	// {
	// 	Bureaucrat br1("Br1", 149);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	
	// {
	// 	Bureaucrat br1("Br1", 150);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	// {
	// 	Bureaucrat br1("Br1", 151);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	// {
	// 	Bureaucrat br1("Br1", 33);

	// 	br1.setGrade(177);
	// 	std::cout << br1;
	// 	br1.setGrade(-99);
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

    // {
	// 	Bureaucrat br1("Br1", 999);

    //     Bureaucrat br2(br1);
    //     // Bureaucrat br2 = br1;
    //     // br2 = br1;
		
	// 	std::cout << br1;
	// 	std::cout << br2;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	{
		Form fm1;
		Form fm2("myForm", 11, 33);
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	{
		Form fm1("myForm", 166, 0);
		
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	{
		Bureaucrat br1("Hans", 100);
		Form fm1("Form_A", 10, 10);
		fm1.beSigned(br1);
		br1.setGrade(5);
		fm1.beSigned(br1);
		//fm1.beSigned(br1);
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	{
		Bureaucrat br1("Joseph", 5);
		Form fm1("Form-A", 2, 1);
		br1.signForm(fm1);
	}

	return 0;
}
