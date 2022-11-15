/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/14 19:23:38 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
	In the constr. there are no try/catch blocks, only if () { throw() }
	The try/catch are in the main. Any Bureaucrat must always be created/incremented ... in the try block.
	If it is created outside the try block and has invalid grade, there is no catch block to catch 
	the throw() from the constructor, so  it is 'uncought exception' and aborts. 
	
	
	Changed: Now a bur. with invalid grade cannot exist and cannot be created.
	Before I could create it, but it would later complain, ie: when copying a bureaucrat.
	

	THIS SYNTAX IS NOT CLEAR:  what() and throw()    both in the function name ???
		const char* Bureaucrat::GradeTooHighException::what() const throw()
		{
			return (LRD"   Thrown exception, Grade Too High\n" RES);
		}

*/


/*	QUESTIONS

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
	std::cout << GRE"Default constr:   name " << _name << ",  grade " << _grade << "\n" RES;
}


// Param. constr.
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	//_someMemory = new char[1024]; // might be lost => memory leak
	//std::cout << "Some memory[0]: " << _someMemory[0] << "\n";


	_grade = grade;
	std::cout << GRE"Param. constr. Bureaucrat: name " << _name << ", grade " << _grade << "\n" RES;

	//try
	//{
		if (_grade < 1)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
		if (_grade > 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE CATCH
	//}

	//catch(const std::exception& e)
	//{
	//	std::cout << GRN"   Thrown exception from the param constr\n" RES;
	//	std::cerr << e.what() << '\n';
	//}
	//delete someMemory;
}



// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name + "_copy")
{
	std::cout << GRE"Copy constructor. Bureaucrat:   " << _name << "\n" RES;
	*this = src;
}



// Overload operators
Bureaucrat& Bureaucrat::operator= (const Bureaucrat &src)
{
	std::cout << GRE"Overload operator=  " << _name << "\n" RES;

	if (this == &src)
		return *this;

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
	
	this->_grade = src._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << GRE"Destructor Bureaucrat: " << _name << "\n" RES;
	//delete _someMemory;
}


//////////////////////////////////////////////////////////

// Public member functions

// CLASS INSIDE CLASS


void	Bureaucrat::incr_grade()
{
	std::cout << BLU"   Incrementing grade " << this->_grade << "\n" RES;

	// Exceptions
	// try
	// {
		if (_grade < 2)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		_grade--;
	// }
	// catch(const std::exception& e)
	// {
	//	std::cerr << e.what() << '\n';
	// }
}



void	Bureaucrat::decr_grade()
{
	std::cout << BLU"   Decrementing grade " << this->_grade << "\n" RES;

	// try
	// {
		if (_grade >= 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		_grade++;
	// }
	// catch(const std::exception& e)
	// {
	//	std::cerr << e.what() << '\n';
	// }
}



// Getter
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
	std::cout << BLU"   Setting grade " << _grade << " to " << grade << "\n" RES;

	//try
	//{
		if (grade < 1)
			throw GradeTooHighException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW

		else if (grade > 150)
			throw GradeTooLowException();	// CREATES/RETURNS THE CLASS, WHICH IS DETECTED BY THE THROW
		//else
		this->_grade = grade;
	//}

	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}

}


// THIS IS OUTSIDE OF THE CLASS !!!
std::ostream& operator<< (std::ostream& outstream, Bureaucrat &bur)
{
	outstream << "Bureaucrat name: " << bur.getName() << ", grade " << bur.getGrade() <<"\n";
	return (outstream);
}
