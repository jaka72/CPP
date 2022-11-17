/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:35:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 14:16:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string   _name;
		const int           _reqGradeSign;
		const int           _reqGradeExec;
		bool                _isSigned;

	public:
		// Constructor
		Form();
		
		// Param. constr.
		Form(std::string name, int gradeSign, int gradeExec);
		
		// Destructor
		~Form() throw();

		// Copy constructor
		Form(const Form& src);
		
		// Overload operators
		Form& operator= (const Form& src);

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const char* msg) throw();                
				const char* what() const throw();
				//GradeTooHighException() throw();
				//~GradeTooHighException() throw();				
		};
		
		class GradeTooLowException  : public std::exception
		{
			public:
				GradeTooLowException(const std::string msg) throw();                
				const char* what() const throw();
				// GradeTooLowException() throw();                
				//~GradeTooLowException() throw();
		};

		// Getters
		std::string getName() const;
		bool        getIsSigned() const;
		int         getReqGradeSign() const;
		int         getReqGradeExec() const;

		// Setters
		void    setIsSigned(bool b);
		
		// Public member functions
		void    beSigned(Bureaucrat& bur);

};

// Operator<< overload
std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
