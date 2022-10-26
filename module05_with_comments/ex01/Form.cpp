/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:55:58 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/26 17:39:31 by jaka          ########   odam.nl         */
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
        if (_reqGradeSign < 1)
            throw GradeTooHighException("   Required grade to sign this form is above the allowed treshold");
        if (_reqGradeExec < 1)
            throw GradeTooHighException("   Required grade to execute this form is above the allowed treshold");
    }

    catch (const GradeTooHighException& e) // derived catch blocks go first
	{
		std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch(const std::exception& e)
    {
        std::cerr << LRD "   After too high, Some other exception occured: " RES << e.what() << '\n';
    }
    
    
    try
    {
        if (_reqGradeSign > 150)
            throw GradeTooLowException("   Required grade to sign this form is below the allowed treshold (150)");
        if (_reqGradeExec > 150)
            throw GradeTooLowException("   Required grade to execute this form is below the allowed treshold (150)");
            // throw GradeTooLowException();
    }
    
    catch (const GradeTooLowException& e) // derived catch blocks go first
	{
		std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch(const std::exception& e)
    {
        std::cerr << LRD "   After too low, Some other exception occured: " RES << e.what() << '\n';
    }
    
}

// Copy constructor

// Destructor
Form::~Form() throw()
{
	std::cout << GRE"Destructor Form:  " << _name << "\n" RES;
}

// Overload operators


// Public member functions
void    Form::beSigned(Bureaucrat& bur)
{
    try
    {   // maybe it can be shorter (if, then throw, = true to the end)      
        if (bur.getGrade() <= this->_reqGradeSign && this->_isSigned == false)
        {
            this->_isSigned = true;
            std::cerr << GRN"   This form can be signed.\n" RES;
            bur.signForm(*this);
        }
        else if (this->_isSigned == true)
        {
            std::cerr << CYN"   This form is already signed.\n" RES;
        }
        else
        {
            // std::string str = "   This form has too high grade to be signed by bureaucrat "; // + bur.getName();
            // const char *msg = str.c_str();
            // const char *msg2 = str.c_str();
            // throw GradeTooLowException(msg2);
            throw GradeTooLowException("   This form has too high grade to be signed by this bureaucrat"); //+ bur.getName() + "\n");
        }    
    }
    catch (const GradeTooLowException& e)
    {
        std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	}
    catch(const std::exception& e)
    {
        std::cerr << LRD "   After beSigned, Some other exception occured: " RES << e.what() << '\n';
    }
}



// Getter
bool    Form::getIsSigned() const
{
    return (this->_isSigned);
}


std::string Form::getName() const
{
    return (this->_name);
}


// Setter


// Exceptions WHAT()
const char* Form::GradeTooHighException::what(const char* msg) const throw()
// const char* Form::GradeTooHighException::what() const throw()
{
    // std::cout << "   From what: print msg " << msg << "\n"; 
    return (msg);
    // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
}



const char* Form::GradeTooLowException::what(const char* msg) const throw()
{
    return (msg);
    // return (MAG"   what: This form has too low the reqGradeSign or reqGradeExec!" RES);
}



Form::GradeTooHighException::GradeTooHighException() throw()
{
   	std::cout << GRE"   Default constr Form::Exception GradeTooHigh\n" RES;
}


Form::GradeTooHighException::GradeTooHighException(const char *msg) throw()
{
   	std::cout << GRE"   Param constr Form::Exception GradeTooHigh\n" RES;
   	//std::cout << GRN << msg << "\n" RES;
    _msg = msg;
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
   	std::cout << GRE"   Destruct Form::Exception GradeTooHigh\n" RES;
}


////////////

Form::GradeTooLowException::GradeTooLowException() throw()
{
   	std::cout << GRE"   Default constr Form::Exception GradeTooLow\n" RES;
}


Form::GradeTooLowException::GradeTooLowException(const char *msg) throw()
{
   	std::cout << GRE"   Param constr Form::Exception GradeTooLow\n" RES;
   	//std::cout << GRN << msg << "\n" RES;
    _msg = msg;
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
   	std::cout << GRE"   Destruct Form::Exception GradeTooLow\n" RES;
}
