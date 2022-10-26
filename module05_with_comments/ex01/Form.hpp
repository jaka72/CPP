/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:35:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/26 15:28:50 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _reqGradeSign;
        const int           _reqGradeExec;

    public:
		// Constructor
        Form();
        
		// Param. constr.
        Form(std::string name, int gradeSign, int gradeExec);
        
		// Destructor
        ~Form() throw();

		// Copy constructor
		
        // Overload operators


		// Exceptions

        class GradeTooHighException : public std::exception
        {
            public:
                const char* _msg;

                GradeTooHighException() throw();
                GradeTooHighException(const char* msg) throw();                
                ~GradeTooHighException() throw();
                
                const char* what(const char* msg) const throw();
                // const char* what() const throw();
        };
        
        class GradeTooLowException  : public std::exception
        {
            public:
                const char* _msg;

                GradeTooLowException() throw();
                GradeTooLowException(const char* msg) throw();                
                ~GradeTooLowException() throw();

                const char* what(const char* msg) const throw();
                // const char* what() const throw();
        };

        // Getters
        std::string getName() const;
        bool        getIsSigned() const;
        int         getReqGradeSign() const;
        int         getReqGradeExec() const;
        
        // Public member functions
        void    beSigned(Bureaucrat& bur);

};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif