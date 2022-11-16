/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:23:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/16 16:14:23 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_H
#define INTERN_H

#include "colors.h"
// #include <iostream>
// #include <exception>
#include <string>
#include "Form.hpp"
// #include "ShrubberyCreationForm.hpp"	// to recognize the dummy form


class Form; // Is this needed?


class Intern
{
	private:

		Form *_form[4];

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


		// DUMMY WRONG FORM
		class WrongForm : public virtual ShrubberyCreationForm  //, public std::exception
		{
			private:
				std::string	_name;
				
			public:
				WrongForm()
				{
					std::cout << "      Default constr Wrongform\n";
				}
				WrongForm(std::string formName) : ShrubberyCreationForm("xxxwww", 0, 0) // ShrubberyCreationForm(formName, "no target")
				{	
					std::cout << "       Param constr WrongForm, " << getName() << "\n";
				};
				~WrongForm()
				{	};
				void beSigned(Bureaucrat& bur) //override
				{
					std::cout << "   BE SIGNED: " << LRD"Form [" << getName() << "] not recognized, cannot sign.\n" RES;
				}
				void execute(const Bureaucrat& bur) //override
				{
					std::cout << "   EXECUTE: " << LRD"Form [" << getName() << "] not recognized, cannot execute.\n" RES;
				}

			
				const char *what() const throw();  // NOT SURE IF THIS NEEDED ???
		};
};

#endif
