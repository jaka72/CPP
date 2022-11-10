/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/28 07:55:31 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// If I make a separate class for GradeTooHighException, it is error c98
// Apparently this class must be declared inside class Bureaucrat ???
// Bureaucrat (DELETED ACCIDENTALY)


/*
	Inside the param. constr. there is try+catch blocks. If grade is invalid, the try throws a 
	creation of the class GradeTooHighException(). The throw is caught by catch the 
	just created class, which calls function what() from this created class.
	wait() gives the according message.


	Operator<< overload must be outside the class in the header !!!!!
	

	The throw() specifier after function what() declares that Wat will never throw an exception.

	
	
*/


/*	QUESTIONS
	- What if it's initiated with too low grade, do we stop or is he allowed to increase
		grade? (and vice versa?)
		I allow to call increase, but then it doesnt increase, just throws message too low 

	- If I try to copy a bureaucrat which has grade too low, is it allowed to copy? 
*/




// FUNCTION wait() IN CLASS INSIDE CLASS,  DERIVED FROM std::exception
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return (LRD"   Thrown exception, Grade Too High\n" RES);
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return (LRD"   Thrown exception, Grade Too Low\n" RES);
}



// Constructor
Bureaucrat::Bureaucrat() : _name("Default")
{
	_grade = 150;
	std::cout << GRE"Default constr. Bureacurat:   name " << _name << ",  grade " << _grade << "\n" RES;
}


// Param. constr.
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	_grade = grade;
	std::cout << GRE"Param. constr. Bureacurat: name " << _name << ", grade " << _grade << "\n" RES;

	try
	{
		if (_grade < 1)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH

		if (_grade > 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name + "_copy")
{
	std::cout << GRE"Copy constr. Bureacurat:   " << _name << "\n" RES;
	*this = src;
}



// Overload operators
Bureaucrat& Bureaucrat::operator= (const Bureaucrat &src)
{
	std::cout << GRE"Overload operator=  " << _name << "\n" RES;

	try
	{
		if (src._grade < 1)
		{
			std::cout << LRD"   Copying a bureaucrat with too high grade!\n" RES;
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
		}
		if (src._grade > 150)
		{
			std::cout << LRD"   Copying a bureaucrat with too low grade!\n" RES;
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
		}
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	this->_grade = src._grade;
	// this->_name = src._name; // Name cant be copied to const
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << GRE"Destructor Bureacurat: " << _name << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions

// CLASS INSIDE CLASS


void	Bureaucrat::incr_grade()
{
	std::cout << BLU"   Incrementing grade " << this->_grade << "\n" RES;

	// Exceptions
	try
	{
		if (_grade < 2)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}


void	Bureaucrat::decr_grade()
{
	std::cout << BLU"   Decrementing grade " << this->_grade << "\n" RES;

	try
	{
		if (_grade >= 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}



void   Bureaucrat::signForm(Form &form)
{
    std::cout << "   SIGN FORM:";
	
	if (_grade <= form.getReqGradeSign() && form.getIsSigned() == false)
	{
        form.setIsSigned(true);
		std::cout << GRN" Bur. " << _name << " signed " << form.getName() << "\n" RES;
	}
	else if (_grade > form.getReqGradeSign() && form.getIsSigned() == false)
		std::cout << LRD" Bur. " << _name << " can't sign " << form.getName()
					<< ", his grade is too low (" << _grade <<")\n" RES;
	else if (form.getIsSigned() == true)
		std::cout << GRN" This form is already signed.\n" RES;
}



// Getters /////////////////////////////////////////////////////////

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::string Bureaucrat::getName() const		// maybe return const ???
{
	return this->_name;
}



// Setter
void	Bureaucrat::setGrade(int grade)
{
	std::cout << BLU"   Setting grade from " << _grade << " to " << grade << "\n" RES;

	try
	{
		if (grade < 1)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW

		if (grade > 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		this->_grade = grade;
	}

	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


// THIS IS OUTSIDE OF THE CLASS !!!
std::ostream& operator<< (std::ostream& outstream, Bureaucrat &bur)
{
	outstream << "Bureaucrat " << bur.getName() << ", grade: " << bur.getGrade() <<"\n";
	return (outstream);
}