/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongForm.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 12:14:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/29 19:05:12 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "Form.hpp"
#include "WrongForm.hpp"
#include <iostream> // for files
#include <fstream>  // for files

// #include "colors.h"
// #include <stdio.h>  // temp just for printf


// Constructor
// WrongForm::WrongForm() : _name("Default_form"), _reqGradeSign(1), _reqGradeExec(1)
WrongForm::WrongForm()
        : Form("Form_base", 0, 0), _name("wrong")
{
	std::cout << GRE"   Default constr WrongForm:  " << _name << "\n" RES;
    //_isSigned = false;
    _target = "file_default";
}


// Param. constr.
WrongForm::WrongForm(std::string formName)
                       : Form("Base_form", 145, 137), _name(formName)
{
	std::cout << GRE"   Param. constr Wrong:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    //_isSigned = false;
//    _target = targetFile;
    

    // NO TRY/CATCH CHECKING NEEDED HERE,
    // BECAUSE ALL VALUES ARE FIXED ABOVE IN INIT. LIST
}



// Destructor
WrongForm::~WrongForm() throw()
{
    // WILL READ FROM BASE: Form
	std::cout << GRE"   Destructor Wrong:  " << _name << "\n" RES;
}


// Copy constructor

// Overload operators


// Public member functions
void    WrongForm::execute(const Bureaucrat&)
{
    std::cout << "   EXECUTE:";

    std::cout << LRD" Cannot execute, non-existing form: " << this->_name << "\n" RES;   
}

// APPARENTLY CANNOT HAVE EXTRA FILES, LIKE THIS ONE 
// NEED TO FIND A WAY TO PUT THIS DUMMY FORM INTO THE CLASS OF THE INTERN ?????

void    WrongForm::beSigned(Bureaucrat&)
{
    std::cout << "   BE SIGNED:";

    std::cout << LRD" Cannot sign, non-existing form: " << this->_name << "\n" RES;   

    
}



// Getter
// bool    WrongForm::getIsSigned() const
// {
//     return (this->_isSigned);
// }



// THIS ONE IS = 0 IN THE FORM HEADER FILE
std::string WrongForm::getName() const
{
    return (this->_name);
}


// Setter





// THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

// WrongForm::GradeTooHighException::GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooHigh\n" RES;
// }


// WrongForm::GradeTooHighException::GradeTooHighException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooHigh\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// WrongForm::GradeTooHighException::~GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooHigh\n" RES;
// }

// // Exceptions WHAT()
// const char* WrongForm::GradeTooHighException::what(const char* msg) const throw()
// // const char* Form::GradeTooHighException::what() const throw()
// {
//     // std::cout << "   From what: print msg " << msg << "\n"; 
//     return (msg);
//     // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
// }



////////////

// WrongForm::GradeTooLowException::GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooLow\n" RES;
// }


// WrongForm::GradeTooLowException::GradeTooLowException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooLow\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// // Destructor
// WrongForm::GradeTooLowException::~GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooLow\n" RES;
// }

// const char* WrongForm::GradeTooLowException::what(const char* msg) const throw()
// {
//     return (msg);
//     // return (MAG"   what: This form has too low the reqGradeSign or reqGradeExec!" RES);
// }

