/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:24:13 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 11:24:45 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"


// Constructor
Intern::Intern()
{
	std::cout << GRE"Default constr. Intern\n" RES;
}



// Copy constructor
Intern::Intern(const Intern &src)
{
	std::cout << GRE"Copy constr. Intern\n" RES;

	*this = src;
}


// Overload operators
Intern& Intern::operator= (const Intern &src)
{
	std::cout << GRE"Overload operator=  , Intern\n" RES;
	
	if (this == &src)
		return *this;
		
	// No vars to copy
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << GRE"Destructor Intern\n" RES;
}


//////////////////////////////////////////////////////////

Form *makePardonForm(const std::string target)  // &target arg cannot be a referrence ??? maybe because
{												//  this function returns a pointer ???
	return (new PresidentialPardonForm(target));
}

Form *makeSchrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *makeRobotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}




Form*  Intern::makeForm(std::string formName, std::string formTarget)
{	
	formPointers[0] = &makePardonForm;
	formPointers[1] = &makeSchrubberyForm;
	formPointers[2] = &makeRobotomyForm;
	
	std::string formNames[] = {"pardon request", "schrubbery request", "robotomy request"};

	int i = 0;
	while (i < NR_FORMS)
	{
		if (formName == formNames[i])
		{
			std::cout << CYN"   Intern has made the Form: [" << formName << "] for target: " << formTarget << "\n" RES;
			return (formPointers[i](formTarget)); // MUST BE DELETED IN MAIN!
		}
		i++;
	}
	
	std::cout << LRD"   Intern cannot create this form. Name [" << formName << "] doesn't exist." << "\n" RES;
	return (NULL);
}
