/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 12:50:13 by jmurovec      ########   odam.nl         */
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

		// Getters
		std::string   getTarget(void) const;

		
		// Public member functions
		void    execute(const Bureaucrat& bur) const;
		void    makeDrillNoise() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
