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

// Constructor
PresidentialPardonForm::PresidentialPardonForm()
					   : Form("PardonForm", 25, 5), _target("file_default")
{
	std::cout << GRE"   Default constr PardonForm:  " << _name << "\n" RES;
}


// Param. constr.
PresidentialPardonForm::PresidentialPardonForm(std::string targetFile)
					   : Form("PardonForm", 25, 5), _target(targetFile)
{
	std::cout << GRE"   Param. constr PardonForm:  " << _name << ",  sign "
			  << _reqGradeSign << ",  exec " << _reqGradeExec << "\n" RES;
}


// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src)
						: Form("PardonForm", 25, 5), _target(src._target)
{
	std::cout << GRE"   Copy constructor PardonForm:  " << _name << "\n" RES;
	*this = src;
}



// Destructor
PresidentialPardonForm::~PresidentialPardonForm() throw()
{
	std::cout << GRE"   Destructor PardonForm:  " << _name << "\n" RES;
}


// Overload operators
PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	// nothing to assign, all are const
	return (*this);
}


// Public member functions

// THIS FUNC COULD MAYBE BE DEFINED ONLY IN THE BASE, AND CALL A GENERIC FUNCTION, IE 
//   execute_task(), WHICH WOULD BE DIFFERENT IN EVERY CHILD FORM
void    PresidentialPardonForm::execute(const Bureaucrat& bur) const
{
	std::cout << "   EXECUTE FORM: ";
	
	if (this->_isSigned == false)
	{
		std::cout << LRD"This form is not yet signed, cannot execute.\n" RES;
		//return ;
	}
	else if (bur.getGrade() > this->getReqGradeExec())
		throw GradeTooLowException("      Can't execute, this bureaucrat has too low grade.");
	else
	{
		std::cout << GRN"Bureaucrat " << bur.getName() << " executed " << this->_name << "\n" RES;
		this->pardonize();
	} 
}


void	PresidentialPardonForm::pardonize() const
{
	std::cout << MAG"                 Mr. " << _target << " has been pardoned by Zaphod Beeblebrox.\n" RES;
}


// Getters
std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}
