/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 21:25:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/29 21:24:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream> // for files
#include <fstream>  // for files

// #include "colors.h"
// #include <stdio.h>  // temp just for printf


// Constructor
// ShrubberyCreationForm::ShrubberyCreationForm() : _name("Default_form"), _reqGradeSign(1), _reqGradeExec(1)
ShrubberyCreationForm::ShrubberyCreationForm()
                       : Form("Form_base", 145, 137), _name("shrubbery request")
{
	std::cout << GRE"   Default constr ShrubberyForm:  " << _name << "\n" RES;
    //_isSigned = false;
    _target = "file_default";
}


// Param. constr.
ShrubberyCreationForm::ShrubberyCreationForm(std::string targetFile)
                       : Form("Base_form", 145, 137), _name("shrubbery request")
{
	std::cout << GRE"   Param. constr ShrubberyForm:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    //_isSigned = false;
    _target = targetFile;
    // NO TRY/CATCH CHECKING NEEDED HERE,
    // BECAUSE ALL VALUES ARE FIXED ABOVE IN INIT. LIST
}



// Param. constr. II  // ADDED TO HELP SAVE NAME TO WRONGFORM
// THIS IS PROBBLY UNNECESSARY
// THE 0 0 ARGS DOES NOT DO ANYTHING, CAN REMOVE 
ShrubberyCreationForm::ShrubberyCreationForm(std::string formName, int x, int y)
                       : Form("Base_form_wrong", 0, 0), _name(formName)
{
	std::cout << GRE"   Param. II constr ShrubberyForm:  " << _name << ",  sign " << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
    //_isSigned = false;
    //_target = targetFile;
    // NO TRY/CATCH CHECKING NEEDED HERE,
    // BECAUSE ALL VALUES ARE FIXED ABOVE IN INIT. LIST
}




// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
    // WILL READ FROM BASE: Form
	std::cout << GRE"   Destructor ShrubberyForm:  " << _name << "\n" RES;
}


// Copy constructor

// Overload operators


// Public member functions
void    ShrubberyCreationForm::execute(const Bureaucrat& bur)
{
    std::cout << "   EXECUTE:";
    try
    {
        if (this->_isSigned == false)
        {
            std::cout << LRD" This form is not yet signed, cannot execute.\n" RES;
            return ; // MAYBE NOT NEEDED, TRY ADDING TO NEXT IF, ISSIGNED IS TRUE
        }
        if (bur.getGrade() > this->getReqGradeExec())
            throw GradeTooLowException(" can't execute: bureaucrat's grade too low.");
        else
        {
            std::cout << GRN" Bur. " << bur.getName() << " executed " << this->_name << "\n" RES;
            this->print_shrubbery();
        }
    }
    catch (GradeTooLowException& e)
    {
        std::cerr << LRD" Catch (shrubbery): " << e.what(e._msg) << "\n" RES;
    }
    catch (const std::exception& e)
    {
        std::cerr << LRD " Catch (shrubbery), other exception: " RES << e.what() << '\n';
    }   
}


void    ShrubberyCreationForm::print_shrubbery()
{
    std::cout << MAG"   Drawing shrubbery to file: " << _target << "\n" RES;
    
    this->_target = this->_target + "_shrubbery";
    const char *str = this->_target.c_str();
    std::ofstream myFile;
    myFile.open(str);
    
    myFile << "\n\n\n\n\n";
    myFile << "      \\ | /\n";
    myFile << "     \\--o--/       o       o\n";
    myFile << "    \\wWWWWWw/     WWWWW   WWWWW\n";
    myFile << "    --wWWWw--       WWW     WWW\n";
    myFile << "     / wWw \\        W       W\n";
    myFile << "       /|\\         |       |\n";
    myFile.close();
}


//void    ShrubberyCreationForm::ShrubberyCreationForm::beSigned(Bureaucrat& bur)
//{

    // SHOULD READ FROM BASE: Form

    // try
    // {   // maybe it can be shorter (if, then throw, = true to the end)      
    //     if (bur.getGrade() <= this->_reqGradeSign && this->_isSigned == false)
    //     {
    //         this->_isSigned = true;
    //         std::cerr << GRN"   This form can be signed.\n" RES;
    //         bur.signForm(*this);
    //     }
    //     else if (this->_isSigned == true)
    //     {
    //         std::cerr << CYN"   This form is already signed.\n" RES;
    //     }
    //     else
    //     {
    //         // std::string str = "   This form has too high grade to be signed by bureaucrat "; // + bur.getName();
    //         // const char *msg = str.c_str();
    //         // const char *msg2 = str.c_str();
    //         // throw GradeTooLowException(msg2);
    //         throw GradeTooLowException("   This form has too high grade to be signed by this bureaucrat"); //+ bur.getName() + "\n");
    //     }    
    // }
    // catch (const GradeTooLowException& e)
    // {
    //     std::cerr << LRD"   Catch: " << e.what(e._msg) << "\n" RES;
	// }
    // catch(const std::exception& e)
    // {
    //     std::cerr << LRD "   After beSigned, Some other exception occured: " RES << e.what() << '\n';
    // }
// }



// Getter
// bool    ShrubberyCreationForm::getIsSigned() const
// {
//     return (this->_isSigned);
// }



// THIS ONE IS = 0 IN THE FORM HEADER FILE
std::string ShrubberyCreationForm::getName() const
{
    return (this->_name);
}


// Setter





// THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

// ShrubberyCreationForm::GradeTooHighException::GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooHigh\n" RES;
// }


// ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooHigh\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// ShrubberyCreationForm::GradeTooHighException::~GradeTooHighException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooHigh\n" RES;
// }

// // Exceptions WHAT()
// const char* ShrubberyCreationForm::GradeTooHighException::what(const char* msg) const throw()
// // const char* Form::GradeTooHighException::what() const throw()
// {
//     // std::cout << "   From what: print msg " << msg << "\n"; 
//     return (msg);
//     // return (MAG"   what: This form has too high the reqGradeSign or reqGradeExec!" RES);
// }



////////////

// ShrubberyCreationForm::GradeTooLowException::GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Default constr ShrubForm::Exception GradeTooLow\n" RES;
// }


// ShrubberyCreationForm::GradeTooLowException::GradeTooLowException(const char *msg) throw()
// {
//    	std::cout << GRE"   Param constr ShrubForm::Exception GradeTooLow\n" RES;
//    	//std::cout << GRN << msg << "\n" RES;
//     _msg = msg;
// }

// // Destructor
// ShrubberyCreationForm::GradeTooLowException::~GradeTooLowException() throw()
// {
//    	std::cout << GRE"   Destruct ShrubForm::Exception GradeTooLow\n" RES;
// }

// const char* ShrubberyCreationForm::GradeTooLowException::what(const char* msg) const throw()
// {
//     return (msg);
//     // return (MAG"   what: This form has too low the reqGradeSign or reqGradeExec!" RES);
// }

