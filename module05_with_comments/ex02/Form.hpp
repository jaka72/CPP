/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 10:35:57 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 21:32:04 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"

class Form
{
    protected:
        const std::string   _name;
        bool                _isSigned;
        const int           _reqGradeSign;
        const int           _reqGradeExec;
        std::string         _target;

    public:
		// Constructor
        Form();
        
		// Param. constr.
        Form(std::string name, int gradeSign, int gradeExec);
        
		// Destructor
        virtual ~Form() throw();

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
                virtual ~GradeTooLowException() throw();

                const char* what(const char* msg) const throw();
                // const char* what() const throw();
        };

        // Getters
        virtual std::string getName() const  =  0;
        virtual bool        getIsSigned() const;
        virtual int         getReqGradeSign() const;
        virtual int         getReqGradeExec() const;
        
        
        // Setters
        virtual void    setIsSigned(bool b);

        
        // Public member functions
        virtual void    beSigned(Bureaucrat& bur);


        //void

};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif