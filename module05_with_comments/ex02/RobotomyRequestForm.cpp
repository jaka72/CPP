/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:20:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 21:49:38 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream> // for files
#include <fstream>  // for files
#include <cstdlib>  // for rand()

// #include "colors.h"
// #include <stdio.h>  // temp just for printf


// Constructor
// RobotomyRequestForm::RobotomyRequestForm() : _name("Default_form"), _reqGradeSign(1), _reqGradeExec(1)
RobotomyRequestForm::RobotomyRequestForm()
                       : Form("Form_base", 72, 45), _name("RobotomyForm")
{
	std::cout << GRE"   Default constr RobotomyForm:  " << _name << "\n" RES;
    //_isSigned = false;
    _target = "file_default";   // NOT SURE IF CUSTOM VARS ARE ALLOWED HERE? MAYBE BETTER IN THE BASE CLASS
}


// Param. constr.
RobotomyRequestForm::RobotomyRequestForm(std::string targetFile)
                       : Form("Base_form", 72, 45), _name("Robotomy_form")
{
	std::cout << GRE"   Param. constr RobotomyForm:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    //_isSigned = false;
    _target = targetFile;       // NOT SURE IF CUSTOM VARS ARE ALLOWED HERE? MAYBE BETTER IN THE BASE CLASS
    
    // NO TRY/CATCH CHECKING NEEDED HERE,
    // BECAUSE ALL VALUES ARE FIXED ABOVE IN INIT. LIST
}



// Destructor
RobotomyRequestForm::~RobotomyRequestForm() throw()
{
    // WILL READ FROM BASE: Form
	std::cout << GRE"   Destructor RobotomyForm:  " << _name << "\n" RES;
}


// Copy constructor

// Overload operators


// Public member functions
void    RobotomyRequestForm::execute(const Bureaucrat& bur)
{
    std::cout << GRE"   EXECUTE:\n" RES;
    
    try
    {
        if (this->_isSigned == false)
        {
            std::cout << LRD"   This form is not yet signed, cannot execute.\n" RES;
            return ;
        }
        if (bur.getGrade() > this->getReqGradeExec())
            throw GradeTooLowException("   Catch robotomy: Can't execute, this bureaucrat has too low grade.");
        else
        {
            std::cout << GRN"   Bureacrat " << bur.getName() << " executed " << this->_name << "\n" RES;
            this->makeDrillNoise(); // MAYBE CHANGE TO 'TARGET_STRING' OR SOMETHING, BECAUSE IT CAN BE USED FOR DIFFERENT PURPOSE
        }
    }
    catch (GradeTooLowException& e)
    {
        std::cerr << LRD << e.what(e._msg) << "\n" RES;
    }
    catch (const std::exception& e)
    {
        std::cerr << LRD "   After too low, Some other exception occured: " RES << e.what() << '\n';
    }   
}



//void    RobotomyRequestForm::RobotomyRequestForm::beSigned(Bureaucrat& bur)
//{ }    // SHOULD READ FROM BASE: Form

// Getters
// bool    RobotomyRequestForm::getIsSigned() const
// { }    // SHOULD READ FROM BASE: Form



// THIS ONE IS = 0 IN THE FORM HEADER FILE
std::string RobotomyRequestForm::getName() const
{
    return (this->_name);
}


// Setter




// Member Functions;
void    RobotomyRequestForm::makeDrillNoise()
{
    std::cout << GRE"   MAKE DRILL NOISE ...\n" RES;

    srand(time(0));
    int r = rand() % 2;
    
    if (r == 0)
        std::cout << "      Robotomy of " << _target << " SUCCESS.\n";
    else
        std::cout << "      Robotomy of " << _target << " FAILED.\n";
 
}



// THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

// RobotomyRequestForm::GradeTooHighException::GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooHigh\n" RES;
// }


// RobotomyRequestForm::GradeTooHighException::GradeTooHighException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooHigh\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// RobotomyRequestForm::GradeTooHighException::~GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooHigh\n" RES;
// }

// // Exceptions WHAT()
// const char* RobotomyRequestForm::GradeTooHighException::what(const char* msg) const throw()
// // const char* Form::GradeTooHighException::what() const throw()
// {
//     // std::cout << "   From what: print msg " << msg << "\n"; 
//     return (msg);
//     // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
// }



////////////

// RobotomyRequestForm::GradeTooLowException::GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooLow\n" RES;
// }


// RobotomyRequestForm::GradeTooLowException::GradeTooLowException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooLow\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// // Destructor
// RobotomyRequestForm::GradeTooLowException::~GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooLow\n" RES;
// }

// const char* RobotomyRequestForm::GradeTooLowException::what(const char* msg) const throw()
// {
//     return (msg);
//     // return (MAG"   what: This form has too low the reqGradeSign or reqGradeExec!" RES);
// }

