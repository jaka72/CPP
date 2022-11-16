/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 13:15:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H


#include <fstream>  // for files
#include <cstdlib>  // for rand
#include <iostream>
#include <exception>

#include "colors.h"
#include "Form.hpp"
#include "Bureaucrat.hpp"

// class RobotomyRequestForm : public Form	// tblase has no virtual ????
class RobotomyRequestForm : public virtual Form
{
	private:
		const std::string	 _target;
		
	public:
		// Constructor
		RobotomyRequestForm();
		
		// Param. constructor
		RobotomyRequestForm(std::string targetFile);
		
		// Copy constructor
		RobotomyRequestForm(RobotomyRequestForm &src);
		
		// Destructor
		~RobotomyRequestForm() throw();
		
		// Overload operators
		RobotomyRequestForm &operator= (RobotomyRequestForm &src);

		// Exceptions
		// THE EXCEPTIONS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN CHILDREN, 
		// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT IS CLASS INSIDE CLASS )
		// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

		// Getters
		std::string   getTarget(void) const;

		
		// Public member functions
		void    execute(const Bureaucrat& bur) const;
		void    makeDrillNoise() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
