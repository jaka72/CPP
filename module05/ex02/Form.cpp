/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:55:58 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/18 16:25:54 by jmurovec      ########   odam.nl         */
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
	std::cout << GRE"Copy constr. Form:  " << _name << "\n" RES;
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
	std::cout << "   SIGN FORM: ";
	if (bur.getGrade() <= getReqGradeSign() && getIsSigned() == false)
	{
		setIsSigned(true);
		std::cout << GRN"   Bureaucrat " << _name << " signed the form " << getName() << "\n" RES;
	}
	else if (bur.getGrade() > getReqGradeSign() && getIsSigned() == false)
	{
		throw GradeTooLowException("   Bureaucrat can't sign the form, because his sign grade is too low.");
	}
	else if (getIsSigned() == true)
	{
		std::cout << CYN"   This form is already signed.\n" RES;
	}
}


// THIS IS PURE VIRTUAL FUNCTION IN THE HEADER.
// void	Form::execute(Bureaucrat const & executor) const
// {
//     std::cout << "EXECUTE (from Base)";
    
// 	if (this->_isSigned == false)
// 	{
// 		std::cout << LRD" IN BASE: This form is not yet signed, cannot execute.\n" RES;
// 		return ;
// 	}
// 	if (executor.getGrade() > this->getReqGradeExec())
// 		throw GradeTooLowException(" IN BASE: Can't execute, this bureaucrat has too low grade.");
// 	else
// 	{
// 		std::cout << GRN" IN BASE: Bureaucrat " << executor.getName() << " executed " << this->_name << "\n" RES;
// 	}
// }


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


// Override  what() 
const char* Form::GradeTooHighException::what() const throw()
{
	//return ("");
	return (LRD"   (exception from Form)\n" RES);
}


const char* Form::GradeTooLowException::what() const throw()
{
	//return ("");
	return (LRD"   (exception from Form)\n" RES);
}
//////////////////////////////////////////////////////////////////////
