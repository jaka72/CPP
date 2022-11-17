/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 11:45:02 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



void internMakesSchrubbery()
{
	
	std::cout << YEL "\n\nTEST: Intern makes Schrubbery Form  - - - - - - - - - -\n\n" RES;

	Bureaucrat	bur1("Steve", 5);
	Intern		intern1;
	
	Form*		form1  = intern1.makeForm("schrubbery request", "PaperA");
	if (form1 == NULL)
		return ;
	std::cout << *form1;

	form1->beSigned(bur1);
	form1->execute(bur1);

	std::cout << *form1;
	if (form1 != NULL)
		delete form1;
}


void internMakesRobotomy()
{
	
	std::cout << YEL "\n\nTEST: Intern makes Robotomy Form  - - - - - - - - - -\n\n" RES;

	Bureaucrat	bur1("Leticia", 3);
	Intern		intern1;
	
	Form*		form1  = intern1.makeForm("robotomy request", "robot");
	if (form1 == NULL)
		return ;
	std::cout << *form1;

	form1->beSigned(bur1);
	form1->execute(bur1);

	if (form1 != NULL)
		delete form1;
}


void internMakesPardon()
{
	
	std::cout << YEL "\n\nTEST: Intern makes Pardon Form  - - - - - - - - - -\n\n" RES;

	Bureaucrat	bur1("Boris", 3);
	Intern		intern1;
	
	Form*		form1  = intern1.makeForm("pardon request", "Kelly");
	if (form1 == NULL)
		return ;
	std::cout << *form1;

	form1->beSigned(bur1);
	form1->execute(bur1);

	if (form1 != NULL)
		delete form1;
}


void internMakesWrongForm()
{
	std::cout << YEL "\n\nTEST: Intern makes a wrong form  - - - - - - - - - -\n\n" RES;

	Bureaucrat	bur1("Lucia", 3);
	Intern		intern1;
	
	Form*		form1  = intern1.makeForm("xxx wrong", "target");
	if (form1 == NULL)
		return ;

	form1->beSigned(bur1);
	form1->execute(bur1);

	if (form1 != NULL)
		delete form1;
}



int main()
{	
	{
		try
		{
			internMakesSchrubbery();
			internMakesRobotomy();
			internMakesPardon();
			internMakesWrongForm();
		}

		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
