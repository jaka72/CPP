/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 08:23:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/28 16:37:44 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_H
#define INTERN_H

#include "colors.h"
// #include <iostream>
// #include <exception>
#include <string>
#include "Form.hpp"


class Form; // Is this needed?


class Intern
{
	private:

//		int					_grade;
//		const std::string	_name;

	public:

		// Constructor
		Intern();
		
		// Param. constr.
		//Intern(std::string name, int grade);

		// Copy constructor
		Intern(const Intern &src);

		// Destructor
		~Intern();

		// Overload operators
		Intern &operator= (const Intern &src);


		// Public member functions
		//void	incr_grade();
		//void	decr_grade();
		Form  *makeForm(std::string formName, std::string formTarget);

		//void test1();

		//void    signForm(Form &form);


		// Getter
		//int			getGrade() const;
		//std::string getName() const;		// maybe return const ???


		// Setter
		//void	setGrade(int grade);


		// Exceptions
		// CLASS INSIDE CLASS
		// class GradeTooHighException : public std::exception
		// {
        //     // public:
    	// 		const char* what() const throw();
		// };

        // // CLASS INSIDE CLASS
		// class GradeTooLowException : public std::exception
		// {
        //     // public:
    	// 		const char* what() const throw();
		// };
};

//std::ostream &operator<< (std::ostream& outstream, Intern& bur);

#endif
