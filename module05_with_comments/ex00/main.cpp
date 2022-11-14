/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/14 11:50:43 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/*
	I decided to move the try/catch blocks to the main. First I had them in the constructors.
	But that would mean that a Bur with an invalid grade would throw an exeption, but he 
	would still be created, instead of stopping the program, after throwing exeption. 
*/

int main()
{
	{
		Bureaucrat br1;
		std::cout << br1;

        Bureaucrat br2(br1);
		// std::cout << br1;
		std::cout << br2;

        Bureaucrat br3 = br2;
		std::cout << br3;

        Bureaucrat br4;
        br4 = br3;
		std::cout << br4;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Jonas", 0);

		br1.incr_grade();
		std::cout << br1;
		br1.decr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	
	
	{
		Bureaucrat br1("Marko", 1);

		br1.incr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Suzana", 149);

		br1.decr_grade();
		std::cout << br1;
		br1.decr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	

	{
		Bureaucrat br1("Peter", 150);

		br1.decr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Emanuel", 151);

		br1.decr_grade();
		std::cout << br1;
		br1.incr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Bureaucrat br1("Lidia", 33);

		br1.setGrade(177);
		std::cout << br1;
		br1.setGrade(-99);
		std::cout << br1;
		br1.setGrade(50);
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


    {
		// SHALL IT COPY, IF GRADE IS OUT OF RANGE, OR REFUSE TO COPY ???
		Bureaucrat br1("Jordan", 999);

        Bureaucrat br2(br1);
        // Bureaucrat br2 = br1;
        // br2 = br1;
		
		std::cout << br1;
		std::cout << br2;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	  {
		// SHALL IT COPY, IF GRADE IS OUT OF RANGE, OR REFUSE TO COPY ???
		Bureaucrat br1("Jordan", 200);
		std::cout << br1;


        // Bureaucrat br2(br1);
        // // Bureaucrat br2 = br1;
        // // br2 = br1;
		
		// std::cout << br1;
		// std::cout << br2;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	return 0;
}











//////////////////////////////////////////////////////////////////
 
int	main_try_inside_func()
{
	// Bureaucrat b0("Jonas", 0);
	// std::cout << b0;


	// b0.incr_grade();
	// std::cout << b0;


	// b0.setGrade(1);
	// std::cout << b0;

	// b0.incr_grade();
	// std::cout << b0;

	// b0.decr_grade();
	// std::cout << b0;
	
	// b0.decr_grade();
	// std::cout << b0;

	// b0.setGrade(150);
	// b0.decr_grade();
	// b0.incr_grade();
	return 0;
}
