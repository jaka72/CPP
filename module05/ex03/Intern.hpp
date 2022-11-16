/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:23:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 17:51:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_H
#define INTERN_H

#include <string>
#include "Form.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.h"


// #include "ShrubberyCreationForm.hpp"	// to recognize the dummy form


class Form; // Is this needed?

#define NR_FORMS 3


class Intern
{
	private:

		//Form *(*formPointers2[3]);		// Form is Abstract, only possible via pointer

		Form *(*formPointers[NR_FORMS])(std::string formTarget);		// Form is Abstract, only possible via pointer



	public:

		// Constructor
		Intern();
		
		// Copy constructor
		Intern(const Intern &src);

		// Destructor
		~Intern();

		// Overload operators
		Intern &operator= (const Intern &src);


		// Public member functions
		Form  *makeForm(std::string formName, std::string formTarget);
};

#endif
