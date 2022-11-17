/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/17 15:12:30 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	{
		std::cout << YEL"Test: Create and copy default bureaucrat - - - - - - - - - - - - - - -\n\n" RES;

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
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Incrementing, decrementing a grade - - - - - - - - - - - - - - -\n\n" RES;
		
		Bureaucrat br1;
		
		try
		{
			for (int i = 0; i < 3; i++)
				br1.incr_grade();
			std::cout << br1 << "\n";
			
			for (int i = 0; i < 4; i++)
				br1.decr_grade();
			std::cout << br1 << "\n";
		}

		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";	
		}
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Create bureaucrats with invalid grade - - - - - - - - - - - - - - -\n\n" RES;

		try
		{
			Bureaucrat br1("Filip", 5);
			std::cout << br1 << "\n";
			
			Bureaucrat br3("Suzana", 500);
			std::cout << br3 << "\n";
		}

		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";	
		}
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test 5: Create *bureaucrats as pointers - - - - - - - - - - - - - - -\n\n" RES;
		Bureaucrat *br1 = NULL;
		Bureaucrat *br2 = NULL;
		Bureaucrat *br3 = NULL;
		
		try
		{
			br1 = new Bureaucrat("John", 5);
			std::cout << *br1 << "\n";

			br2 = new Bureaucrat("Nina", 5);
			std::cout << *br2 << "\n";
			
			br3 = new Bureaucrat("Lex", 999);
			std::cout << *br3 << "\n";
		}

		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n";	
		}
		
		if (br1)
			delete br1;
		if (br2)
			delete br2;
		if (br3)
			delete br3;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	//system ("leaks a.out");
	return 0;
}
