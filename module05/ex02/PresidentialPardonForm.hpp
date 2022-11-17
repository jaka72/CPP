/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 12:36:38 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include <fstream>  // for files
#include <cstdlib>  // for rand()
#include <iostream>
#include <exception>

#include "colors.h"
#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public virtual Form
{
	private:
		const std::string	_target;

	public:
		// Constructor
		PresidentialPardonForm();
		
		// Param. constructor
		PresidentialPardonForm(std::string targetFile);
		
		// Copy constructor
		PresidentialPardonForm(PresidentialPardonForm &src);
		
		// Destructor
		~PresidentialPardonForm() throw();
		
		// Overload operators
		PresidentialPardonForm &operator= (const PresidentialPardonForm &src);

		/// Exceptions

		// Getters
		std::string getTarget(void) const;


		// Public member functions
		void    execute(const Bureaucrat& bur) const;

		void    pardonize() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
