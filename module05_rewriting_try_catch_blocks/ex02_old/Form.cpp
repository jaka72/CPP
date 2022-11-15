/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:55:58 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/28 08:01:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
// #include "colors.h"
#include <stdio.h>  // temp just for printf


// Constructor
Form::Form() : _name("Default_form"), _reqGradeSign(1), _reqGradeExec(1)
{
	std::cout << GRE"Default constr Form:  " << _name << "\n" RES;
    _isSigned = false;
}


// Param. constr.
Form::Form(std::string name, int rgs, int rge) : _name(name), _reqGradeSign(rgs), _reqGradeExec(rge)
{
	std::cout << GRE"Param. constr Form:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    _isSigned = false;
    try
    {
        if (_reqGradeSign < 1 || _reqGradeExec < 1)
            throw GradeTooHighException("   This form has invalid sign or execute grade (too high).");
        if (_reqGradeSign > 150 || _reqGradeExec > 150)
            throw GradeTooLowException("   This form has invalid sign or execute grade (too low).");
    }

    catch (const GradeTooHighException& e) // derived catch blocks go first
	{
		std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch (const GradeTooLowException& e) // derived catch blocks go first
	{
		std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch(const std::exception& e)
    {
        std::cerr << LRD "   After too high, Some other exception occured: " RES << e.what() << '\n';
    }    
}


// Destructor
Form::~Form() throw()
{
	std::cout << GRE"Destructor Form:  " << _name << "\n" RES;
}


// Copy constructor

// Overload operators



// Public member functions
void    Form::beSigned(Bureaucrat& bur)
{
    std::cout << "   BE SIGNED:";

    try
    {   // maybe it can be shorter (if, then throw, = true to the end)      
        if (this->_isSigned == true)
            std::cerr << CYN" This form is already signed.\n" RES;
        else if (bur.getGrade() < 1)
            throw GradeTooHighException(" Cannot sign. This bureacrat has invalid grade (too high).");
        else if (bur.getGrade() > 150)
            throw GradeTooLowException(" Cannot sign. This bureacrat has invalid grade (too low).");            
        else if (bur.getGrade() <= this->_reqGradeSign && this->_isSigned == false)
        {
            std::cerr << GRN" This form can be signed.\n" RES;
            bur.signForm(*this);
        }
        else
            throw GradeTooLowException(" This form has too high grade to be signed by this bureaucrat"); //+ bur.getName() + "\n");
    }
    catch (const GradeTooHighException& e)
    {
        std::cerr << LRD" Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch (const GradeTooLowException& e)
    {
        std::cerr << LRD" Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch(const std::exception& e)
    {
        std::cerr << LRD " Catch: Some other exception occured: " RES << e.what() << '\n';
    }
}



// Getters ///////////////////////////////////////////////////

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


// Setters //////////////////////////////////////////////////////////////

void    Form::setIsSigned(bool b)
{
    this->_isSigned = b;
}


// EXCEPTIONS ///////////////////////////////////////////////////////////

Form::GradeTooHighException::GradeTooHighException() throw()
{
   	// std::cout << GRE"   Default constr Form::Exception GradeTooHigh\n" RES;
}


Form::GradeTooHighException::GradeTooHighException(const char *msg) throw()
{
   	// std::cout << GRE"   Param constr Form::Exception GradeTooHigh\n" RES;
   	//std::cout << GRN << msg << "\n" RES;
    _msg = msg;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
   	// std::cout << GRE"   Destruct Form::Exception GradeTooHigh\n" RES;
}

// Exceptions WHAT()
const char* Form::GradeTooHighException::what(const char* msg) const throw()
// const char* Form::GradeTooHighException::what() const throw()
{
    // std::cout << "   From what: print msg " << msg << "\n"; 
    return (msg);
    // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
}


////////////////////////////


Form::GradeTooLowException::GradeTooLowException() throw()
{
   	// std::cout << GRE"   Default constr Form::Exception GradeTooLow\n" RES;
}


Form::GradeTooLowException::GradeTooLowException(const char *msg) throw()
{
   	// std::cout << GRE"   Param constr Form::Exception GradeTooLow\n" RES;
   	//std::cout << GRN << msg << "\n" RES;
    _msg = msg;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
   	// std::cout << GRE"   Destruct Form::Exception GradeTooLow\n" RES;
}

// Exceptions WHAT()
const char* Form::GradeTooLowException::what(const char* msg) const throw()
// const char* Form::GradeTooHighException::what() const throw()
{
    // std::cout << "   From what: print msg " << msg << "\n"; 
    return (msg);
    // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
}
