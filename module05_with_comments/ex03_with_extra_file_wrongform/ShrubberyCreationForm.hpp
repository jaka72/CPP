/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 21:25:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 21:37:10 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */





#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public virtual Form // should be virtual here ???
// class ShrubberyCreationForm    : public         Form // should be virtual here ???
{
    private:
        //std::string         _target;
        const std::string   _name;  // according to subject, it must be in the base class,
                                    // but then both parent & child must have same name
        // bool                _isSigned;
        // const int           _reqGradeSign;
        // const int           _reqGradeExec;

    public:
		// Constructor
        ShrubberyCreationForm();
        
		// Param. constr.  - NOT USED
        ShrubberyCreationForm(std::string targetFile);
        
		// Destructor
        ~ShrubberyCreationForm() throw();

		// Copy constructor
		
        // Overload operators


		// Exceptions
        
    // THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
    // BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
    // SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

        // class GradeTooHighException : public std::exception
        // {
        //     public:
        //         const char* _msg;

        //         // constructors
        //         GradeTooHighException() throw();
        //         GradeTooHighException(const char* msg) throw();                
        //         ~GradeTooHighException() throw();
                
        //         const char* what(const char* msg) const throw();
        //         // const char* what() const throw();
        // };
        
        // class GradeTooLowException  : public std::exception
        // {
        //     public:
        //         const char* _msg;

        //         // constructors
        //         GradeTooLowException() throw();
        //         GradeTooLowException(const char* msg) throw();                
        //         ~GradeTooLowException() throw();

        //         const char* what(const char* msg) const throw();
        //         // const char* what() const throw();
        // };

        // Getters
        std::string getName() const; // THIS FUNC MUST BE PRESENT, BECAUSE IN BASE-FORM IS SET TO = 0
        //bool        getIsSigned() const;
        //int         getReqGradeSign() const;
        //int         getReqGradeExec() const;
        
        // Public member functions
        void    execute(const Bureaucrat& bur);
        void    print_shrubbery();

        //void    beSigned(Bureaucrat& bur);

};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif