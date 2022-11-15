/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/14 18:46:05 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "colors.h"

class Bureaucrat
{
	private:

		int					_grade;
		const std::string	_name;



	public:
		//char* _someMemory; // might be lost => memory leak

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


		// Getter
		int			getGrade() const;
		std::string getName() const;		// maybe return const ???


		// Setter
		void	setGrade(int grade);


		// Exceptions
		// CLASS INSIDE CLASS
		class GradeTooHighException : public std::exception
		{
            public:
    			           const char* what() const throw();
    			// virtual const char* what() const throw();	// WHY SHOULD BETTER BE VIRTUAL ???
																// IF THIS IS A CHILD CLASS, DERIVED FROM exception
		};

        // CLASS INSIDE CLASS
		class GradeTooLowException : public std::exception
		{
            public:
    			const char* what() const throw();
		};



};

std::ostream &operator<< (std::ostream& outstream, Bureaucrat& bur);

#endif
