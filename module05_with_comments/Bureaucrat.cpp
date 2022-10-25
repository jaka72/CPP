/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/23 18:51:27 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


// Constructor
// Bureaucrat::Bureaucrat(int grade = 0) //: _name("set name in initializor")
// Bureaucrat::Bureaucrat(std::string name = "default", int grade = 0) //: _name("set name in initializor")
Bureaucrat::Bureaucrat() : _name("Default")
{
	_grade = 44;
	std::cout << "Default constr. name: " << getName() << "\n";
	std::cout << "Default constr. grade: " << getGrade() << "\n";
}


// Param. constr.
// Bureaucrat::Bureaucrat(std::string name = "default", int grade = 0) : _name(name)	// Conflict with default constr, thinks they are the same
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	// if (grade < 1 || grade > 150)
	// 	std::cout << "Should throw exeption\n";
	// HOW TO STOP/RETURN THE CONSTR IF THE ARG GRADE IS TOO HIGH??
	
	_grade = grade;
	this->GradeTooHighException();
	this->GradeTooLowException();
}


// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	
}


// Overload operators
Bureaucrat &Bureaucrat::operator= (const Bureaucrat &src)
{
	return *this;
}



// Exceptions
void Bureaucrat::GradeTooHighException()
{
	try
	{
		if (this->_grade <= 1)
			throw "      Exception: Grade is too high, must be > 1\n";
	}
	
	catch(const char* str)
	{
		std::cerr << str;
	}
}



void Bureaucrat::GradeTooLowException()
{
	try
	{
		if (this->_grade <= 1 || this->_grade >= 150)
			throw "      Exception: Grade is too low, must be < 150\n";
		_grade++;
		std::cout << "      Grade is now " << this->_grade << "\n";
	}
	
	catch(const char* str)
	{
		std::cerr << str;
	}
}




// Public member functions
void	Bureaucrat::incr_grade()
{
	std::cout << "   Incrementing grade " << this->_grade << "\n";
	this->GradeTooHighException();
	if (this->_grade <= 150)
	{
		_grade--;
		std::cout << "      Grade is now " << this->_grade << "\n";
	}
}



void	Bureaucrat::decr_grade()
{
	std::cout << "   Decrementing grade " << this->_grade << "\n";
	this->GradeTooLowException();
	if (this->_grade >= 150)
	{
		_grade++;
		std::cout << "      Grade is now " << this->_grade << "\n";
	}
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
	std::cout << "   Setting grade " << _grade << " to " << grade << "\n";
	this->_grade = grade;
}



/// //////////////////////////////////////////////////
 
int	main()
{
	Bureaucrat b0("Joco", 160);
	
	std::cout << "getName: " << b0.getName() << "\n";
	std::cout << "getGrade: " << b0.getGrade() << "\n";


	


	// b0.setGrade(1);
	// b0.incr_grade();
	// b0.decr_grade();
	
	// b0.setGrade(150);
	// b0.decr_grade();
	// b0.incr_grade();
}
