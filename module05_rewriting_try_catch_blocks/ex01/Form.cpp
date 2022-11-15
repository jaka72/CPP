/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:55:58 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/15 17:24:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


// Constructor
Form::Form() : _name("DefaultForm"), _reqGradeSign(1), _reqGradeExec(1)
{
	std::cout << GRE"Default constructor Form:  " << _name << "\n" RES;
	_isSigned = false;
}



// Param constructor
Form::Form(std::string name, int rgs, int rge) : _name(name), _reqGradeSign(rgs), _reqGradeExec(rge)
{
	std::cout << GRE"Param. constr Form:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
	_isSigned = false;
		if (_reqGradeSign < 1)
			throw GradeTooHighException("   Cannot create form with invalid Sign Grade (too high).");
			
		if (_reqGradeExec < 1)
			throw GradeTooHighException("   Cannot create form with invalid Execute Grade (too high).");
			
		if (_reqGradeSign > 150)
			throw GradeTooLowException("   Cannot create form with invalid Sign Grade (too low).");

		if (_reqGradeExec > 150)
			throw GradeTooLowException("   Cannot create form with invalid Execute Grade (too low).");  
}



// Destructor
Form::~Form() throw()
{
	std::cout << GRE"Destructor Form:  " << _name << "\n" RES;
}


// Copy constructor
Form::Form(const Form& src)  : _name(src._name + "_copy"), _isSigned(src._isSigned),
					_reqGradeSign(src._reqGradeExec), _reqGradeExec(src._reqGradeExec)
{
	*this = src;
}



// Overload operators
Form& Form::operator= (const Form& src)
{
	this->_isSigned = src._isSigned;
	return (*this);
}



// Public member functions
void    Form::beSigned(Bureaucrat& bur)
{
	std::cout << "   Calling BE SIGNED:\n";

	if (this->_isSigned == true)
		std::cerr << CYN"   This form is already signed.\n" RES;
	else if (bur.getGrade() <= this->_reqGradeSign && this->_isSigned == false)
	{
		std::cerr << GRN"   This form can be signed.\n" RES;
		bur.signForm(*this);
	}
	else
	{
		std::string msg = "   This form has too high grade to be signed by bureaucrat " + bur.getName() + ".\n";
		throw GradeTooLowException(msg);
	}
}



// Getters /////////////////////////////////////////////
bool    Form::getIsSigned() const
{
	return (this->_isSigned);
}


std::string Form::getName() const
{
	return (this->_name);
}

int Form::getReqGradeSign() const
{
	return (this->_reqGradeSign);
}

int Form::getReqGradeExec() const
{
	return (this->_reqGradeExec);
}


// Setters
void    Form::setIsSigned(bool b)
{
	this->_isSigned = b;
}



// Overload for WHAT()
///////////////////////////////////////////////////////////////////
const char* Form::GradeTooHighException::what() const throw()
{
	return ("");
	// return (LRD"   (exception from the Form)" RES);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("");
	// return (LRD"   (exception from the Form)" RES);
}



// Operator<< overload
std::ostream& operator<< (std::ostream& outstream, Form &form)
{
	outstream << DYEL"   Form name:   " << form.getName() << "\n";
	outstream << "   - signed status:             " << form.getIsSigned() << "\n";
	outstream << "   - required grade to sign:    " << form.getReqGradeSign() << "\n";
	outstream << "   - required grade to execute: " << form.getReqGradeExec() << "\n" RES;
	return (outstream);
}



// PARAM CONSTRUCTOR EXCEPTIONS
///////////////////////////////////////////////////////////////////
Form::GradeTooHighException::GradeTooHighException(const char *msg) throw()
{
   	std::cout << LRD << msg << "\n" RES;
}

Form::GradeTooLowException::GradeTooLowException(const std::string msg) throw()
{
   	std::cout << LRD << msg << "\n" RES;
}
//////////////////////////////////////////////////////////////////////


// Destructors Exceptions
// Form::GradeTooLowException::~GradeTooLowException() throw()
// {
//    	// std::cout << GRE"   Destruct Form::Exception GradeTooLow\n" RES;
// }

// Form::GradeTooHighException::~GradeTooHighException() throw()
// {
//    	// std::cout << GRE"   Destruct Form::Exception GradeTooHigh\n" RES;
// }

