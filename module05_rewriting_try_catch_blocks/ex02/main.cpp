/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 14:33:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void testSchruberryForm()
{
	std::cout << "TEST Shrubbery Creation Form - - - - - - - - - - - - -\n\n";

	ShrubberyCreationForm shrub1("target_file");
	std::cout << shrub1;
	Bureaucrat bur1("Erman", 143);
	shrub1.execute(bur1);

	bur1.signForm(shrub1);
	std::cout << GRE"   Check signed status: " << shrub1.getIsSigned() << "\n" RES;

	for (int i = 0; i < 6; i++)
		bur1.incr_grade();
		
	shrub1.execute(bur1);
}



void testRobotomyForm()
{
	std::cout << "TEST Robotomy Request Form - - - - - - - - - - - - -\n\n";
	
	RobotomyRequestForm rob1("target_robot");
	std::cout << rob1;
	Bureaucrat bur1("Sabine", 46);
	rob1.execute(bur1);
	
	bur1.signForm(rob1);
	bur1.signForm(rob1);
	std::cout << GRE"   Check signed status: " << rob1.getIsSigned() << "\n" RES;
	
	for (int i = 0; i < 3; i++)
		bur1.incr_grade();
		
	rob1.execute(bur1);
}



void testPardonForm()
{
	std::cout << "TEST Presidential Pardon Form - - - - - - - - - - - - -\n\n";
	
	PresidentialPardonForm pardon1("Luis");
	std::cout << pardon1;
	Bureaucrat bur1("Felix", 8);
	pardon1.execute(bur1);
	
	bur1.signForm(pardon1);
	bur1.signForm(pardon1);
	std::cout << GRE"   Check signed status: " << pardon1.getIsSigned() << "\n" RES;
	
	for (int i = 0; i < 3; i++)
		bur1.incr_grade();
		
	pardon1.execute(bur1);
}


int main()
{
	try
	{
		testSchruberryForm();
		// testRobotomyForm();
		// testPardonForm();
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
	
	return 0;
}
