/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/26 09:52:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


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
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		
	{
		Bureaucrat br1("Br1", 0);

		br1.incr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	
	{
		Bureaucrat br1("Br1", 1);

		br1.incr_grade();
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	{
		Bureaucrat br1("Br1", 149);

		br1.decr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	
	{
		Bureaucrat br1("Br1", 150);

		br1.decr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	{
		Bureaucrat br1("Br1", 151);

		br1.decr_grade();
		std::cout << br1;
	
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	{
		Bureaucrat br1("Br1", 33);

		br1.setGrade(177);
		std::cout << br1;
		br1.setGrade(-99);
		std::cout << br1;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

    {
		Bureaucrat br1("Br1", 999);

        Bureaucrat br2(br1);
        // Bureaucrat br2 = br1;
        // br2 = br1;
		
		std::cout << br1;
		std::cout << br2;
	}	
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n";

	return 0;
}











//////////////////////////////////////////////////////////////////
 
int	main_try_inside_func()
{
	Bureaucrat b0("Joco", 0);
	std::cout << b0;


	b0.incr_grade();
	std::cout << b0;


	b0.setGrade(1);
	std::cout << b0;

	b0.incr_grade();
	std::cout << b0;

	b0.decr_grade();
	std::cout << b0;
	
	b0.decr_grade();
	std::cout << b0;

	// b0.setGrade(150);
	// b0.decr_grade();
	// b0.incr_grade();
	return 0;
}
