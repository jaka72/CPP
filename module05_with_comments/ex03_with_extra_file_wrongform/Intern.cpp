/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:24:13 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/29 12:33:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>	// exit
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "WrongForm.hpp"
#include "Intern.hpp"



// FUNCTION wait() IN CLASS INSIDE CLASS,  DERIVED FROM std::exception
// const char* Intern::GradeTooHighException::what() const throw()
// {
// 	return (LRD"   Thrown exception, Grade Too High\n" RES);
// }


// const char* Intern::GradeTooLowException::what() const throw()
// {
// 	return (LRD"   Thrown exception, Grade Too Low\n" RES);
// }



// Constructor
Intern::Intern()
{
	std::cout << GRE"Default constr. Intern\n" RES;
}


// Param. constr.
//Intern::Intern(std::string name, int grade)
//{
//	std::cout << GRE"Param. constr. Intern\n" RES;

	// try
	// {
	// 	if (_grade < 1)
	// 		throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH

	// 	if (_grade > 150)
	// 		throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
	// }

	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
//}



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

	// try
	// {
	// 	if (src._grade < 1)
	// 	{
	// 		std::cout << LRD"   Copying a bureaucrat with too high grade!\n" RES;
	// 		throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
	// 	}
	// 	if (src._grade > 150)
	// 	{
	// 		std::cout << LRD"   Copying a bureaucrat with too low grade!\n" RES;
	// 		throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
	// 	}
	// }

	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	// this->_grade = src._grade;
	// this->_name = src._name; // Name cant be copied to const
	*this = src;
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << GRE"Destructor Intern\n" RES;
	
	int i = 3;
	while (i < 3)
		delete _form[i];
}


//////////////////////////////////////////////////////////

// Public member functions

// int get_level(std::string formName)
// {
// 	std::string arr[3] =
// 	{
// 		"shrubbery request",
// 		"robotomy request",
// 		"pardon request"
// 	};

// 	int i = 0;
// 	while (i < 3)
// 	{
// 		if (formName == arr[i])
// 			return i;
// 		i++;
// 	}
// 	return (i);
// }



Form*  Intern::makeForm(std::string formName, std::string formTarget)
{
	// Form	*f1;
	//int		level = get_level(formName);

	_form[0] = new ShrubberyCreationForm();
	_form[1] = new RobotomyRequestForm();
	_form[2] = new PresidentialPardonForm();
	_form[3] = new WrongForm(formName);
	
	int i = 0;
	while (i < 3)
	{
		if (formName == _form[i]->getName())
		{
			std::cout << "formname: " << _form[i]->getName() << "\n"; 
			std::cout << "formtarget: " << _form[i]->getTarget() << "\n"; 
			_form[i]->setTarget(formTarget);
			
			std::cout << CYN"   The Intern has made the Form: " << formName << "\n" RES;
			return (_form[i]);
		}
		i++;
	}
	
	std::cout << "A) " << i << "\n";
	

	return (_form[i]);
}




// void Intern::test1()
// {
// 	std::cout << "Test from intern1\n";
// }


// CLASS INSIDE CLASS


//void	Intern::incr_grade()
//{
	// std::cout << BLU"   Incrementing grade " << this->_grade << "\n" RES;

	// // Exceptions
	// try
	// {
	// 	if (_grade < 2)
	// 		throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
	// 	_grade--;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
//}


//void	Intern::decr_grade()
//{
	// std::cout << BLU"   Decrementing grade " << this->_grade << "\n" RES;

	// try
	// {
	// 	if (_grade >= 150)
	// 		throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
	// 	_grade++;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
//}



//void   Intern::signForm(Form &form)
//{
//    std::cout << "   SIGN FORM:";
	
	// if (_grade <= form.getReqGradeSign() && form.getIsSigned() == false)
	// {
    //     form.setIsSigned(true);
	// 	std::cout << GRN" Bur. " << _name << " signed " << form.getName() << "\n" RES;
	// }
	// else if (_grade > form.getReqGradeSign() && form.getIsSigned() == false)
	// 	std::cout << LRD" Bur. " << _name << " can't sign " << form.getName()
	// 				<< ", his grade is too low (" << _grade <<")\n" RES;
	// else if (form.getIsSigned() == true)
	// 	std::cout << GRN" This form is already signed.\n" RES;
//}



// Getters /////////////////////////////////////////////////////////

// int			Intern::getGrade() const
// {
// 	return this->_grade;
// }

// std::string Intern::getName() const		// maybe return const ???
// {
// 	return this->_name;
// }



// Setter
//void	Intern::setGrade(int grade)
//{
	// std::cout << BLU"   Setting grade from " << _grade << " to " << grade << "\n" RES;

	// try
	// {
	// 	if (grade < 1)
	// 		throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW

	// 	if (grade > 150)
	// 		throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
	// 	this->_grade = grade;
	// }

	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
//}


// THIS IS OUTSIDE OF THE CLASS !!!
// std::ostream& operator<< (std::ostream& outstream, Intern &bur)
// {
	//outstream << "Intern " << bur.getName() << ", grade: " << bur.getGrade() <<"\n";
	// return (outstream);
// }
