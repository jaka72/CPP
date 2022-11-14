/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 16:19:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/29 20:17:28 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public virtual Form // should be virtual here ???
// class RobotomyRequestForm    : public         Form // should be virtual here ???
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
        RobotomyRequestForm();
        
		// Param. constr.  - NOT USED
        RobotomyRequestForm(std::string targetFile);
        
		// Destructor
        ~RobotomyRequestForm() throw();

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
        void    makeDrillNoise();


        //void    beSigned(Bureaucrat& bur);

};

std::ostream& operator<< (std::ostream& outstream, Form& form);

#endif
