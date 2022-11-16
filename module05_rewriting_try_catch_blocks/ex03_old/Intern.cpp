/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:24:13 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 16:20:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define NR_FORMS 4


// Constructor
Intern::Intern()
{
	std::cout << GRE"Default constr. Intern\n" RES;

	_form[0] = new ShrubberyCreationForm();
	_form[1] = new RobotomyRequestForm();
	_form[2] = new PresidentialPardonForm();
	_form[3] = new WrongForm("Not recognized");
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
		
	// Needs to deep copy the forms array ???  
	
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << GRE"Destructor Intern\n" RES;
	
	int i = 0;
	while (i < NR_FORMS)
	{	
		std::cout << GRE"   delete " << i << ": " << _form[i]->getName() << "\n" RES;
		delete _form[i];
		i++;
	}
}


//////////////////////////////////////////////////////////




Form*  Intern::makeForm(std::string formName, std::string formTarget)
{	
	int i = 0;
	while (i < NR_FORMS)
	{
		if (formName == _form[i]->getName())
		{
			// std::cout << "formname: " << _form[i]->getName() << "\n"; 
			// std::cout << "formtarget: " << _form[i]->getTarget() << "\n"; 
			_form[i]->setTarget(formTarget);
			
			std::cout << CYN"   The Intern has made the Form: " << formName << ", with target: " << formTarget << "\n" RES;
			return (_form[i]);
		}
		i++;
	}
	
	std::cout << "A) i" << i << "\n";
	
	std::cout << LRD"   The Intern has made a Wrong Form: " << formName << ", with target: " << formTarget << "\n" RES;
	return (_form[--i]); // !!! SHOULD GIVE WRONGFORM, INSTEAD OF NOW SHRUBERRY
}


// void Intern::test1()
// {
// 	std::cout << "Test from intern1\n";
// }
