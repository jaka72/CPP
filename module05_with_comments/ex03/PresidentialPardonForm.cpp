/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:20:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 20:56:02 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream> // for files
#include <fstream>  // for files
#include <cstdlib>  // for rand()

// #include "colors.h"
// #include <stdio.h>  // temp just for printf


// Constructor
// PresidentialPardonForm::PresidentialPardonForm() : _name("Default_form"), _reqGradeSign(1), _reqGradeExec(1)
PresidentialPardonForm::PresidentialPardonForm()
                       : Form("BaseForm", 25, 5), _name("PardonForm")
{
	std::cout << GRE"   Default constr PardonForm:  " << _name << "\n" RES;
    //_isSigned = false;
    _target = "defaultTargetPardon";   // NOT SURE IF CUSTOM VARS ARE ALLOWED HERE? MAYBE BETTER IN THE BASE CLASS
}


// Param. constr.
PresidentialPardonForm::PresidentialPardonForm(std::string target)
                       : Form("BaseForm", 25, 5), _name("PardonForm")
{
	std::cout << GRE"   Param. constr PardonForm:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    //_isSigned = false;
    _target = target;       // NOT SURE IF CUSTOM VARS ARE ALLOWED HERE? MAYBE BETTER IN THE BASE CLASS
    
    // NO TRY/CATCH CHECKING NEEDED HERE,
    // BECAUSE ALL VALUES ARE FIXED ABOVE IN INIT. LIST
}



// Destructor
PresidentialPardonForm::~PresidentialPardonForm() throw()
{
    // WILL READ FROM BASE: Form
	std::cout << GRE"   Destructor PardonForm:  " << _name << "\n" RES;
}


// Copy constructor

// Overload operators


// Public member functions
void    PresidentialPardonForm::execute(const Bureaucrat& bur)
{
    std::cout << "   EXECUTE:";
    
    try
    {
        if (this->_isSigned == false)
        {
            std::cout << LRD" This form is not yet signed, cannot execute.\n" RES;
            return ;
        }
        if (bur.getGrade() > this->getReqGradeExec())
            throw GradeTooLowException(" Can't execute, this bureaucrat has too low grade.");
        else
        {
            std::cout << GRN" Bur. " << bur.getName() << " executed " << this->_name << "\n" RES;
            this->pardonize();
        }
    }
    catch (GradeTooLowException& e)
    {
        std::cerr << LRD " Catch (pardon), " << e.what(e._msg) << "\n" RES;
    }
    catch (const std::exception& e)
    {
        std::cerr << LRD " Catch (pardon), other exception: " RES << e.what() << '\n';
    }   
}



void    PresidentialPardonForm::pardonize()
{
    std::cout << MAG"   Mr. " << _target << " has been pardoned by Zaphod Beeblebrox.\n" RES;
}


// THIS ONE IS = 0 IN THE FORM HEADER FILE
std::string PresidentialPardonForm::getName() const
{
    return (this->_name);
}


// Setter




// Member Functions;
// void    PresidentialPardonForm::makeDrillNoise()
// {
//     std::cout << GRE"   MAKE DRILL NOISE ...\n" RES;

//     srand(time(0));
//     int r = rand() % 2;
    
//     if (r == 0)
//         std::cout << "      Robotomy of " << _target << " SUCCESS.\n";
//     else
//         std::cout << "      Robotomy of " << _target << " FAILED.\n";
 
// }



// THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

// PresidentialPardonForm::GradeTooHighException::GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooHigh\n" RES;
// }


// PresidentialPardonForm::GradeTooHighException::GradeTooHighException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooHigh\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// PresidentialPardonForm::GradeTooHighException::~GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooHigh\n" RES;
// }

// // Exceptions WHAT()
// const char* PresidentialPardonForm::GradeTooHighException::what(const char* msg) const throw()
// // const char* Form::GradeTooHighException::what() const throw()
// {
//     // std::cout << "   From what: print msg " << msg << "\n"; 
//     return (msg);
//     // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
// }



////////////

// PresidentialPardonForm::GradeTooLowException::GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooLow\n" RES;
// }


// PresidentialPardonForm::GradeTooLowException::GradeTooLowException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooLow\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// // Destructor
// PresidentialPardonForm::GradeTooLowException::~GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooLow\n" RES;
// }

// const char* PresidentialPardonForm::GradeTooLowException::what(const char* msg) const throw()
// {
//     return (msg);
//     // return (MAG"   what: This form has too low the reqGradeSign or reqGradeExec!" RES);
// }

