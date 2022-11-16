/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 21:25:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 17:59:05 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// #include "Form.hpp"
#include "ShrubberyCreationForm.hpp"


// Constructor
ShrubberyCreationForm::ShrubberyCreationForm()
					   : Form("ShrubberyForm", 145, 137), _target("file_default")
{
	std::cout << GRE"   Default constr ShrubberyForm:  " << _name << "\n" RES;
}


// Param. constr.
ShrubberyCreationForm::ShrubberyCreationForm(std::string targetFile)
					   : Form("Shrubbery_form", 145, 137), _target(targetFile)
{
	std::cout << GRE"   Param. constr ShrubberyForm:  " << _name << ",  sign "
			  << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
}


// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src)
					: Form("ShrubberyForm", 145, 137),	_target(src._target)
{
	std::cout << GRE"   Copy constructor ShrubberyForm:  " << _name << "\n" RES;
	*this = src;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
	std::cout << GRE"   Destructor ShrubberyForm:  " << _name << "\n" RES;
}


// Overload operators
ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm &src)
{
	if (this == &src)
		return (*this);
	// nothing to copy, all vars are const
	return (*this);
}


// THIS FUNC COULD MAYBE BE DEFINED ONLY IN THE BASE, AND CALL A GENERIC FUNCTION, IE 
//   execute_task(), HICH WOULD BE DIFFERENT IN EVERY CHILD FORM
// Public member functions
void    ShrubberyCreationForm::execute(const Bureaucrat& bur) const
{
	std::cout << "   EXECUTE:";

	if (this->_isSigned == false)
	{
		std::cout << LRD"      This form is not yet signed, cannot execute.\n" RES;
	}
	else if (bur.getGrade() > this->getReqGradeExec())
		throw GradeTooLowException("      Can't execute: bureaucrat's grade too low.");
	else
	{
		std::cout << GRN"      Bureaucrat " << bur.getName() << " executed " << this->_name << "\n" RES;
		this->print_shrubbery();
	}
}


void    ShrubberyCreationForm::print_shrubbery() const
{
	std::cout << MAG"                 Drawing shrubbery to file: " << _target << "\n" RES;
	
	std::ofstream outFile (getTarget().append("_shrubbery").c_str());
	
	outFile << "\n\n\n\n\n";
	outFile << "       o       o       o\n";
	outFile << "     WWWWW   WWWWW   WWWWW\n";
	outFile << "      WWW     WWW     WWW\n";
	outFile << "       W       W       W\n";
	outFile << "       |       |       |\n";
	outFile.close();
}


// Getters
std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}
