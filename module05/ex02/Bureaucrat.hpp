/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/18 16:12:08 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "colors.h"

class Form;

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
		void    executeForm(Form const & form);


		// Getter
		int					getGrade() const;
		const	std::string getName() const;


		// Setter
		// void	setGrade(int grade);


		// Exceptions
		class GradeTooLowException : public std::exception
		{
            public:
				//GradeTooLowException() throw();
				GradeTooLowException(const char* msg) throw();
    			const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
            public:
				//GradeTooHighException() throw();               
				GradeTooHighException(const char* msg) throw();               
    			const char* what() const throw();
		};
};

std::ostream &operator<< (std::ostream& outstream, Bureaucrat& bur);

#endif
