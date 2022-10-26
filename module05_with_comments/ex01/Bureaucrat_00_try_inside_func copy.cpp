/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat_00_try_inside_func copy.cpp             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/25 21:46:16 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat_00.hpp"


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
	//this->GradeTooHighException();
	//this->GradeTooLowException();
	std::cout << "Param. constr, name: " << _name << ", grade " << _grade << "\n";
	this->GradeTooLowException();
	this->GradeTooHighException();
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

std::ostream& operator<< (std::ostream& outstream, Bureaucrat &bur)
{
	outstream << "Name: " << bur.getName() << ", grade: " << bur.getGrade() <<"\n";
	return (outstream);
}

// Exceptions
void Bureaucrat::GradeTooHighException()
{
	try
	{
		if (this->_grade <= 0)
		{
			throw "      Thrown exception, grade is too high (< 1)\n";
			this->_grade++;
		}
		else if (this->_grade <= 150)
		{
			std::cout << "      From Exc Too High: Grade is now " << this->_grade << "\n";
		}
	}
	catch (const char *msg)
	{
		std::cerr << msg;
		//exit (2);
	}
}



void Bureaucrat::GradeTooLowException()
{	
	try
	{
		if (this->_grade > 150)
		{
			throw "      Thrown exception, grade is too low (> 150 )\n";
		}
		else if (this->_grade >= 1)
		{
			std::cout << "      From Exc Too Low:  Grade is now " << this->_grade << "\n";
		}
	}
	catch (const char *msg)
	{
		std::cerr << msg;
		//exit (1);
	}
}




// Public member functions
void	Bureaucrat::incr_grade()
{
	std::cout << "   Incrementing grade " << this->_grade << "\n";
	_grade--;
	this->GradeTooHighException();
}



void	Bureaucrat::decr_grade()
{
	std::cout << "   Decrementing grade " << this->_grade << "\n";
	_grade++;
	this->GradeTooLowException();
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
	Bureaucrat b0("Joco", 0);
	std::cout << b0;


	b0.incr_grade();
	std::cout << b0;


	b0.setGrade(1);
	std::cout << b0;

	b0.incr_grade();
	std::cout << b0;

	b0.decr_grade();
	std::cout << b0;
	
	b0.decr_grade();
	std::cout << b0;

	// b0.setGrade(150);
	// b0.decr_grade();
	// b0.incr_grade();
}
