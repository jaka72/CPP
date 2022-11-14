/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/13 20:11:58 by jaka          ########   odam.nl         */
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


	QUESTIONS
	- If trying to copy a bur. with too low grade, shall it copy or refuse to copy?
			- difference in copy(src)  vs   cpy = src

			Three variants:			a)	Bureaucrat br2(br1);		copy constr
        							b)	Bureaucrat br3 = br2;		copy constr
        							c)	Bureaucrat br3;				default +_ overload=
        								   br3 = br2;
*/

int main()
{
	{
		// Bureaucrat br1;
		// std::cout << br1;

        // Bureaucrat br2(br1);
		// // std::cout << br1;
		// std::cout << br2;

        // Bureaucrat br3 = br2;
		// std::cout << br3;

        // Bureaucrat br4;
        // br4 = br3;
		// std::cout << br4;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Rudi", 0);

		br1.incr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		Bureaucrat br1("Natasha", 151);

		br1.decr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Will", 1);

		br1.incr_grade();
		std::cout << br1;
		br1.incr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Maria", 149);

		br1.decr_grade();
		std::cout << br1;
		br1.decr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{

	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";




	{
		Bureaucrat br1("Alfons", 33);

		br1.setGrade(177);
		std::cout << br1;
		br1.setGrade(-99);
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


    {
		Bureaucrat br1("Lidia", 999);

        Bureaucrat br2(br1);
        Bureaucrat br3; // = br2;
        br3 = br2;
		// HOW SHOULD br3 BEHAVE in different copy variants? 
		// Should he preserve Default value 150, if the copy value is out of range?
		// ???


		
		std::cout << br1;
		std::cout << br2;
		std::cout << br3;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Form fm1;
	// 	Form fm2("myForm", 11, 33);
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	// {
	// 	Form fm1("myForm", 166, 0);
		
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Hans", 100);
	// 	Form fm1("Form_A", 10, 10);
	// 	fm1.beSigned(br1);
	// 	br1.setGrade(5);
	// 	fm1.beSigned(br1);
	// 	//fm1.beSigned(br1);
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Joseph", 5);
	// 	Form fm1("Form-A", 2, 1);
	// 	br1.signForm(fm1);
	// }

	return 0;
}
