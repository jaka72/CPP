/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 17:54:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"	// THIS WAS ERROR, WHEN ABOVE SHRUBERRY.HPP !!!
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



void internMakesSchrubbery()
{
	
	std::cout << "TEST: Intern makes Schrubbery Form  - - - - - - - - - -\n\n";

	Bureaucrat	bur1("Steve", 3);
	Intern		intern1;
	
	Form*		shrub1  = intern1.makeForm("schrubbery request", "PaperA");
	if (shrub1 == NULL)
		return ;

	shrub1->beSigned(bur1);
	shrub1->execute(bur1);

	if (shrub1 != NULL)
		delete shrub1;
}


void internMakesRobotomy()
{
	
	std::cout << "TEST: Intern makes Robotomy Form  - - - - - - - - - -\n\n";

	Bureaucrat	bur1("Leticia", 3);
	Intern		intern1;
	
	Form*		robo1  = intern1.makeForm("robotomy request", "robot");
	if (robo1 == NULL)
		return ;

	robo1->beSigned(bur1);
	robo1->execute(bur1);

	if (robo1 != NULL)
		delete robo1;
}


void internMakesPardon()
{
	
	std::cout << "TEST: Intern makes Pardon Form  - - - - - - - - - -\n\n";

	Bureaucrat	bur1("Boris", 3);
	Intern		intern1;
	
	Form*		pardon1  = intern1.makeForm("pardon request", "Kelly");
	if (pardon1 == NULL)
		return ;

	pardon1->beSigned(bur1);
	pardon1->execute(bur1);

	if (pardon1 != NULL)
		delete pardon1;
}


void internMakesWrongForm()
{
	
	std::cout << "TEST: Intern makes a wrong form  - - - - - - - - - -\n\n";

	Bureaucrat	bur1("Lucia", 3);
	Intern		intern1;
	
	Form*		pardon1  = intern1.makeForm("xxx wrong", "target");
	if (pardon1 == NULL)
		return ;

	pardon1->beSigned(bur1);
	pardon1->execute(bur1);

	if (pardon1 != NULL)
		delete pardon1;
}




int main()
{	
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		try
		{
			// internMakesSchrubbery();
			// internMakesRobotomy();
			// internMakesPardon();
			internMakesWrongForm();
		}
		
		
		catch (Form::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
