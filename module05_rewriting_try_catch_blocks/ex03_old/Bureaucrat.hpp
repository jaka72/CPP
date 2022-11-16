/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:54:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/28 08:24:39 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "colors.h"
#include <iostream>
#include <exception>
// #include <string>	// ???
// #include "Form.hpp"


class Form; // Is this needed?


class Bureaucrat
{
	private:

		int					_grade;
		const std::string	_name;

	public:

		// Constructor
		Bureaucrat();
		
		// Param. constr.
		Bureaucrat(std::string name, int grade);

		// Copy constructor
		Bureaucrat(const Bureaucrat &src);

		// Destructor
		~Bureaucrat();

		// Overload operators
		Bureaucrat &operator= (const Bureaucrat &src);


		// Public member functions
		void	incr_grade();
		void	decr_grade();


		void    signForm(Form &form);


		// Getter
		int			getGrade() const;
		std::string getName() const;		// maybe return const ???


		// Setter
		void	setGrade(int grade);


		// Exceptions
		// CLASS INSIDE CLASS
		class GradeTooHighException : public std::exception
		{
            // public:
    			const char* what() const throw();
		};

        // CLASS INSIDE CLASS
		class GradeTooLowException : public std::exception
		{
            // public:
    			const char* what() const throw();
		};
};

std::ostream &operator<< (std::ostream& outstream, Bureaucrat& bur);

#endif
