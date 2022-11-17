/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 13:32:37 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:54:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/23 13:07:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "colors.h"
#include <iostream>
#include <exception>


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


		// Getters
		int					getGrade() const;
		const std::string	getName() const;


		// Setters
		// void	setGrade(int grade);


		// Exceptions
		class GradeTooLowException : public std::exception
		{
            public:
				GradeTooLowException(const char* msg) throw();
    			virtual const char* what() const throw();
		};
		
		class GradeTooHighException : public std::exception
		{
            public:
				GradeTooHighException(const char* msg) throw();               
    			const char* what() const throw();
		};
};

std::ostream &operator<< (std::ostream& outstream, Bureaucrat& bur);

#endif
