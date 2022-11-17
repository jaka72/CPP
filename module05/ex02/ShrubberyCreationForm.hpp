/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 21:25:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 12:50:51 by jmurovec      ########   odam.nl         */
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

		// Getters
		std::string   getTarget(void) const;

		
		// Public member functions
		void    execute(const Bureaucrat& bur) const;
		void    print_shrubbery() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
