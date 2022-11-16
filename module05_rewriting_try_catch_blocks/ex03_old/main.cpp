/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 16:28:14 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"	// THIS WAS ERROR, WHEN ABOVE SHRUBERRY.HPP !!!
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



int main()
{	
	{
		std::cout << "TEST Presidential Pardon Form - - - - - - - - - -\n\n";

		// Bureaucrat bur1("Severin", 111);
		// PresidentialPardonForm pardon1("Rudy");

		// bur1.signForm(pardon1);
		// pardon1.execute(bur1);

		// bur1.setGrade(22);
		// bur1.signForm(pardon1);
		// pardon1.execute(bur1);

		// bur1.setGrade(3);
		// bur1.signForm(pardon1);
		// pardon1.execute(bur1);
	}

	// EX03 ////////////////////////////////////////
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		std::cout << "TEST: Create Intern and call makeform()  - - - - - - - - - -\n\n";

		Bureaucrat bur1("Steve", 3);
		Intern intern1;
		
		// Form* shrub1("targetFile");  // THE TARGET NEEDS TO WORK BELLOW AS THE SECOND ARG
		Form* shrub1;
		//Form* robo1;
		// Form* pardon1;

		shrub1  = intern1.makeForm("shrubbery request", "PaperA");
		//robo1   = intern1.makeForm("robotomy request", "RobotA");
		// pardon1 = intern1.makeForm("pardon request", "Jakob");
		
		shrub1->beSigned(bur1);
		//robo1->beSigned(bur1);
		// pardon1->beSigned(bur1);	

		shrub1->execute(bur1);
		//robo1->execute(bur1);
		// pardon1->execute(bur1);


		// Form* wrong1;
		// wrong1 = intern1.makeForm("wrong request", "Jakob");
		// wrong1->beSigned(bur1);
		// wrong1->execute(bur1);

		// bur1.signForm(*wrong1);
	

	}

	return 0;
}
