/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/15 17:45:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	Attaching suffix _copy to a copy:
		Apparently only possible in Copy constructor  Bureaucrat br2(br1)
		But not in overload=    br3 = br2
		(because in overload you cant use init.list  :      )
		(you can use it only in constructors)
		(so, the _name cannot be changed in overload= ,if it is a const) 


		Differences in copy(src)  vs   cpy = src
		Three variants:			a)	Bureaucrat br2(br1);		copy constr
								b)	Bureaucrat br3 = br2;		copy constr
								c)	Bureaucrat br3;				default +_ overload=
										br3 = br2;
	
	You can do the throw anywhere in the code. It does not have to be in the try block.
	After throw you need to provide something (int, string, class ...)
		throw 1,    throw "some msg",   throw SomeClass
	
	If you wanna throw a class, it can be declared inside another class (ie: class Form
	will create an object Form, but if you try to create it with invalid args, it throws an
	exception. And this exception can be another class, declared inside the Form class.)
	(You can also add custom constructors for your exception class, ie: a constructor with
	a string as a parameter.)
	
	If you wanna throw a class , it can be with or without argm:
		throw SomeClass();						--> calls default constr.
		throw SomeClass("some string", ...);	--> calls param constr.

	In case of class throw, the class must have the brackets:  throw SomeClass()
	This calls the class contructor. In this constructor, you can add other things, 
	like printing something.
		 
	If you put a string in the class throw (ie: throw SomeClass("some string"), you can imm. 
	print it in the constructor of this class.
	For this, you don't need the what() function. 
	
	
	So in which case is good to have a what() ???
	You can also make use of the function what(), which is included in std::exception.
	You can call it in the catch block, like this:
				e.what()    (e is the arg, this the object)
				It returns whatever string, and you can put more code into it.
		 	
				(If there is no override of what() function, it will just print 
				std::exception, when e.what() is used in cathc block.)
	
	
	QUESTIONS:

		- Not clear when this what() is useful? (Now I override each Exception() with
			parma exception(*str), so it always prints specific message. What() I dont use )
*/




int main()
{
	{
		// std::cout << YEL"Test: Create and copy default bureaucrat - - - - - - - - - - - - - - -\n\n" RES;

		// Bureaucrat br1;
		// std::cout << br1;

        // Bureaucrat br2(br1);
		// std::cout << br2;

        // Bureaucrat br3 = br2;
		// std::cout << br3;

        // Bureaucrat br4;
        // br4 = br3;
		// std::cout << br4;
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: all variations - - - - - - - - - - - - - - -\n\n" RES;

		try	// First, all parameters are invalid, try changing one by one
		{
			Form form1("Form_A", 5, 5);	
			std::cout << form1 << "\n";

			Bureaucrat br1("Natasha", 6);
			//br1.setGrade(4);
			br1.incr_grade();
			br1.incr_grade();
			br1.incr_grade();
			//br1.incr_grade();
			form1.beSigned(br1);
			br1.signForm(form1); 
			br1.incr_grade();	
			std::cout << br1;


			form1.beSigned(br1);
			br1.signForm(form1);
			std::cout << form1 << "\n";
		}
		catch (Form::GradeTooLowException &e) // can use specific Exception and add more detailed message
		{
			std::cerr << e.what() << '\n';
			//std::cout << form1;
		}
		catch (Form::GradeTooHighException &e) // can use specific Exception and add more detailed message
		{
			std::cerr << e.what() << '\n';
			//std::cout << form1;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << e.what() << "\n";
		}
		catch(const std::exception& e)  // ANY OTHER EXCEPTION
		{
			//std::cout << form1;
			std::cerr << e.what() << '\n';
		}
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return 0;
}
