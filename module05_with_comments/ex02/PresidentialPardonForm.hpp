/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/27 20:56:02 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public virtual Form // should be virtual here ???
// class PresidentialPardonForm    : public         Form // should be virtual here ???
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
        PresidentialPardonForm();
        
		// Param. constr.  - NOT USED
        PresidentialPardonForm(std::string targetFile);
        
		// Destructor
        ~PresidentialPardonForm() throw();

		// Copy constructor
		
        // Overload operators


		// Exceptions
        
    // THIS CLASS APPARENTLY DOES NOT HAVE TO BE REPEATED IN THIS CHILD, 
    // BUT IN PARENT IT CANNOT BE SET TO VIRTUAL (BECAUSE IT CLASS INSIDE CLASS )
    // SO IT WILL BE ALWAYS USED FROM PARENT, NEVER FROM HERE

        // class GradeTooHighException : public std::exception
        // { }
         
        // class GradeTooLowException  : public std::exception
        // { }

        // Getters
        std::string getName() const; // THIS FUNC MUST BE PRESENT, BECAUSE IN BASE-FORM IS SET TO = 0
        //bool        getIsSigned() const;
        //int         getReqGradeSign() const;
        //int         getReqGradeExec() const;
        
        // Public member functions
        void    execute(const Bureaucrat& bur);
        void    pardonize();


        //void    beSigned(Bureaucrat& bur);

};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
