/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 21:25:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 13:16:59 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H


#include <fstream>  // for files
#include <iostream>
#include <exception>
#include "colors.h"
#include "Form.hpp"
#include "Bureaucrat.hpp"


class ShrubberyCreationForm : public virtual Form
{
	private:
		const std::string	_target;

	public:
		// Constructor
		ShrubberyCreationForm();
		
		// Param. constr.
		ShrubberyCreationForm(std::string targetFile);
		
		// Copy constructor
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		
		// Destructor
		~ShrubberyCreationForm() throw();

		// Overload operators
		ShrubberyCreationForm &operator= (const ShrubberyCreationForm &src);


		// Exceptions
		// THE EXCEPTIONS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN CHILDREN, 
		// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE ITS CLASS INSIDE CLASS )
		// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

		// Getters
		std::string   getTarget(void) const;

		
		// Public member functions
		void    execute(const Bureaucrat& bur) const;
		void    print_shrubbery() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
