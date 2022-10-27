/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 21:52:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



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

// FROM EX01 /////////////////////////////////////////////////////////
// Form is now ABSTRACT, cant be used
	// {
	// 	Form fm1;
	// 	Form fm2("myForm", 11, 33);
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	// {
	// 	Form fm1("myForm", 166, 0);
		
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	// {
	// 	Bureaucrat br1("Hans", 100);
	// 	Form fm1("Form_A", 10, 10);
	// 	fm1.beSigned(br1);
	// 	br1.setGrade(5);
	// 	fm1.beSigned(br1);
	// 	fm1.beSigned(br1);
	// }
//////////////////////////////////////////////////////////



	// EX02 ////////////////////////////////////////
	{
		std::cout << "TEST Shrubbery Creation Form - - - - - - - - - - - - -\n\n";

		Bureaucrat bur1("Erman", -1);
		ShrubberyCreationForm shrub1("target_file");

		std::cout << shrub1.getIsSigned() << "\n";
		shrub1.execute(bur1);

		// Form fm1;
		// bur1.signForm(shrub1);
		shrub1.beSigned(bur1);
		// std::cout << shrub1.getName() << "\n";
		std::cout << shrub1.getIsSigned() << "\n";

		shrub1.execute(bur1);

		bur1.setGrade(5);
		shrub1.beSigned(bur1);
		shrub1.execute(bur1);

	}
			std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		std::cout << "TEST Robotomy Request Form - - - - - - - - - - - - - -\n\n";

		Bureaucrat bur1("George", 6);
		RobotomyRequestForm robo1("target_Robo");

		robo1.beSigned(bur1);
		bur1.signForm(robo1);
		//std::cout << robo1.getIsSigned() << "\n";
		robo1.execute(bur1);

		// Form fm1;
		// bur1.signForm(robo1);
		// std::cout << robo1.getName() << "\n";
		//std::cout << robo1.getIsSigned() << "\n";

		//robo1.execute(bur1);
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	
	{
		std::cout << "TEST Presidential Pardon Form - - - - - - - - - -\n\n";

		Bureaucrat bur1("Severin", 111);
		PresidentialPardonForm pardon1("Kennedy");

		bur1.signForm(pardon1);
		pardon1.execute(bur1);

		bur1.setGrade(22);
		bur1.signForm(pardon1);
		pardon1.execute(bur1);

		bur1.setGrade(3);
		bur1.signForm(pardon1);
		pardon1.execute(bur1);
	}


	return 0;
}
