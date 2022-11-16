/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:20:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 13:22:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm()
					   : Form("RobotomyForm", 72, 45), _target("file_default")
{
	std::cout << GRE"   Default constr RobotomyForm:  " << _name << "\n" RES;
}


// Param. constr.
RobotomyRequestForm::RobotomyRequestForm(std::string targetFile)
					   : Form("Robotomy_form", 72, 45), _target(targetFile)
{
	std::cout << GRE"   Param. constr RobotomyForm:  " << _name << ",  sign "
			  << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
}


// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src)
						: Form("RobotomyForm", 72, 45), _target(src._target)
{
	std::cout << GRE"   Copy constructor RobotomyForm:  " << _name << "\n" RES;
	*this = src;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm() throw()
{
	std::cout << GRE"   Destructor RobotomyForm:  " << _name << "\n" RES;
}


// Overload operators
RobotomyRequestForm&  RobotomyRequestForm::operator= (RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	// nothing to copy, all vars are const
	return (*this);
}


// Public member functions
void    RobotomyRequestForm::execute(const Bureaucrat& bur) const
{
	std::cout << "   EXECUTE:";

	if (this->_isSigned == false)
	{
		std::cout << LRD"      This form is not yet signed, cannot execute.\n" RES;
		//return ;
	}
	else if (bur.getGrade() > this->getReqGradeExec())
		throw GradeTooLowException("      Can't execute, this bureaucrat's grade too low.");
	else
	{
		std::cout << GRN"      Bureaucrat " << bur.getName() << " executed " << this->_name << "\n" RES;
		this->makeDrillNoise();
	}
}


void    RobotomyRequestForm::makeDrillNoise() const
{
	std::cout << MAG"                 Making drilling noise ... ";

	srand(time(0));
	int r = rand() % 2;
	
	if (r == 0)
		std::cout << "  Robotomy of " << _target << ": SUCCESS.\n" RES;
	else
		std::cout << "  Robotomy of " << _target << ": FAILED.\n" RES;
}



// Getters
std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}
