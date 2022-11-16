/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 20:56:02 by jaka          ########   odam.nl         */
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
		const std::string	_target;    // must be here, but not in base class (probably because the base
										// is considered a template, which only has the most crucial vars, 
										// but specific vars we only put into children)

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
		// THE EXCEPTIONS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN CHILDREN, 
		// BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE ITS CLASS INSIDE CLASS )
		// SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE


		// Getters
		std::string getTarget(void) const;


		// Public member functions
		void    execute(const Bureaucrat& bur) const;

		void    pardonize() const;
};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
