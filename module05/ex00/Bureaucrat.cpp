/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 15:10:43 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


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
	std::cout << GRE"Param. constr. Bureaucrat: name " << _name << ", grade " << _grade << "\n" RES;

	//try
	//{
		if (_grade < 1)
			throw GradeTooHighException("Cannot create this bureaucrat: invalid grade (too high)");	
		if (_grade > 150)
			throw GradeTooLowException("Cannot create this bureaucrat: invalid grade (too low)");	
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
}



// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name + "_copy")
{
	std::cout << GRE"Copy constr. Bureaucrat:   " << _name << "\n" RES;
	*this = src;
}



// Overload operators
Bureaucrat& Bureaucrat::operator= (const Bureaucrat &src)
{
	std::cout << GRE"Overload operator=  " << _name << "\n" RES;

	if (this == &src)
		return *this;
	
	this->_grade = src._grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << GRE"Destructor Bureaucrat: " << _name << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions

// CLASS INSIDE CLASS
void	Bureaucrat::incr_grade()
{
	std::cout << BLU"   Incrementing grade " << _grade << " to " << _grade - 1 << "\n" RES;

	// Exceptions
	//try
	//{
		if (_grade < 2)
			throw GradeTooHighException("Cannot increment higher than 1!");
		_grade--;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
}



void	Bureaucrat::decr_grade()
{
	std::cout << BLU"   Decrementing grade " << _grade << " to " << _grade + 1 << "\n" RES;

	//try
	//{
		if (_grade >= 150)
			throw GradeTooLowException("Cannot increment lower than 150!");
		_grade++;
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
}



// Getters /////////////////////////////////////////////////////////////////

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string Bureaucrat::getName() const
{
	return this->_name;
}



// Setters //////////////////////////////////////////////////////////////////

// void	Bureaucrat::setGrade(int grade)
// {
// 	std::cout << BLU"   Setting grade from " << _grade << " to " << grade << "\n" RES;

// 	if (grade < 1)
// 		throw GradeTooHighException("Cannot set invalid grade (too high)");

// 	else if (grade > 150)
// 		throw GradeTooLowException("Cannot set invalid grade (too low)");
	
// 	this->_grade = grade;
// }


// THIS IS OUTSIDE OF THE CLASS !!!
std::ostream& operator<< (std::ostream& outstream, Bureaucrat &bur)
{
	outstream << "Bureaucrat name: " << bur.getName() << ", grade " << bur.getGrade() <<"\n";
	return (outstream);
}



//////////////////////////////////////////////////////////////////////
// Default constructor for Exceptions
// (not needed)


// Param. constructor for Exceptions
Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) throw()
{
   	std::cout << LRD << msg << "\n" RES;
}
Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) throw()
{
   	std::cerr << LRD << msg << "\n" RES;
}
//////////////////////////////////////////////////////////////////////



// Override  what() 
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	// return ("");
	return (LRD"   (exception from Bureaucrat)\n" RES);
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	//return ("");
	return (LRD"   (exception from Bureaucrat)\n" RES);
}
//////////////////////////////////////////////////////////////////////
