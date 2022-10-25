/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:54:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/23 13:07:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

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

		// Getter
		int			getGrade() const;
		std::string getName() const;		// maybe return const ???

		// Setter
		void	setGrade(int grade);


		// Exceptions
		void GradeTooHighException_old();
		void GradeTooLowException_old();

		// CLASS INSIDE CLASS
		class GradeTooHighException : public std::exception
		{
            // public:
    			const char* what() const throw();
		};

};

#endif
