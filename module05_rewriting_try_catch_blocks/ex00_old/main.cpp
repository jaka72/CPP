/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 08:43:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/14 19:40:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


/*
	I decided to move the try/catch blocks to the main. First I had them in the constructors.
	But that would mean that a Bur with an invalid grade would throw an exeption, but he 
	would still be created, instead of stopping the program, after throwing exeption. 

	But now I see, that it is an error abort, if you create object with invalid grade outside of
	any try! Error comes because the throw() is called without being in any try block.

	So, I decided to remove the try/catch in the constructor, but I leave the throw() ,so the object
	is not created. So it can not print its name in the main (will segfault).
	But I do remove try/catch blocks from the functions incr(), decr() and setGrade(). This way I can
	create Bur in main, inside and outside of try block. Tblase gets abort, if creates Bur outside of try.
	
	If I create invalid Bur in main inside a try, it will throw exception from the catch in constructor,
	and ignore the catch in the main. But I thing this is fine - better than abort.
	The only thing is that it will still create the object with invalid grade. Maybe its better in this 
	case to set the invalid grade to the lowest grade.

*/





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
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Setting a grade - - - - - - - - - - - - - - -\n\n" RES;
		Bureaucrat br1;
		try
		{
			br1.setGrade(33);
			br1.setGrade(1);
			br1.setGrade(0);
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << LRD"Cannot set " << br1.getName() << "'s grade: " << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << LRD"Cannot set " << br1.getName() << "'s grade: " << e.what() << "\n";
		}
		std::cout << br1 << "\n";
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Incrementing a grade - - - - - - - - - - - - - - -\n\n" RES;
		Bureaucrat br1("Jonas", 100);
		try
		{
			br1.incr_grade();
			br1.incr_grade();
			br1.incr_grade();
			br1.setGrade(3);
			br1.incr_grade();
			br1.incr_grade();
			br1.incr_grade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << LRD"Cannot decrement " << br1.getName() << "'s grade: " << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << LRD"Cannot increment " << br1.getName() << "'s grade: " << e.what() << "\n";
		}
		std::cout << br1 << "\n";	
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Decrementing a grade - - - - - - - - - - - - - - -\n\n" RES;
		Bureaucrat br1("Natasha", 100);
		try
		{
			br1.decr_grade();
			br1.decr_grade();
			br1.decr_grade();
			br1.setGrade(148);
			br1.decr_grade();
			br1.decr_grade();
			br1.decr_grade();
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << LRD"Cannot decrement " << br1.getName() << "'s grade: " << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << LRD"Cannot increment " << br1.getName() << "'s grade " << e.what() << "\n";
		}
		std::cout << br1 << "\n";
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";



	{
		std::cout << YEL"Test: Create pointer *bureaucrats with invalid grade - - - - - - - - - - - - - - -\n\n" RES;
		Bureaucrat *br1 = NULL;
		Bureaucrat *br2 = NULL;
		Bureaucrat *br3 = NULL;
		
		try
		{
			br1 = new Bureaucrat("Filip", 5);
			std::cout << *br1 << "\n";
			br2 = new Bureaucrat("Roby", 5);
			std::cout << *br2 << "\n";
			br3 = new Bureaucrat("Suzana", 999);
			std::cout << *br3 << "\n"; // SEGFAULT: CANNOT PRINT IT, BECAUSE IT WAS NOT CREATED
										// WAS RETURNED FROM THE CONSTRUCTOR
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << LRD"Cannot create bureaucrat: " << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << LRD"Cannot create bureaucrat: " << e.what() << "\n";
		}
		
		
		if (br1)
			delete br1;
		if (br2)
			delete br2;
		if (br3)
			delete br3;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";



	{
		std::cout << YEL"Test: Create non-pointer bureaucrats with invalid grade - - - - - - - - - - - - - - -\n\n" RES;
		
		//char* someMemory = NULL; // might be lost => memory leak // temp, just for testing

		try
		{
			// std::cout << "Some memory[0]: " << someMemory[0] << "\n";
			//someMemory = new char[1024]; // might be lost => memory leak
	
			Bureaucrat br1("Filip", 5);
			std::cout << br1 << "\n";
			Bureaucrat br2("Roby", 5);
			std::cout << br2 << "\n";
			Bureaucrat br3("Suzana", 500 );
			std::cout << LRD"~~~~~~~~~~~~~~~~~~~~~~ after invalid grade\n";

			std::cout << br3 << "\n"; // SEGFAULT: CANNOT PRINT IT, BECAUSE IT WAS NOT CREATED
										// WAS RETURNED FROM THE CONSTRUCTOR
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << LRD"Cannot create bureaucrat: " << e.what() << "\n";
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << LRD"Cannot create bureaucrat: " << e.what() << "\n";
		}
		//delete someMemory;
	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << YEL"Test: Create bureaucrats with invalid grade, Outside try block, will abort - - - - - - - - - - - - - - -\n\n" RES;

		// //char *someMemory = new char[1024]; // might be lost => memory leak
		// //std::cout << "Some memory[0]: " << someMemory[0] << "\n";

		// Bureaucrat br3("Monica", 5);	// If invalid grade, it causes valgrind "possibly lost memory"
		// std::cout << br3 << "\n";
		// //delete someMemory;

	}
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Jonas", 0);

	// 	br1.incr_grade();
	// 	std::cout << br1;
	// 	br1.decr_grade();
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	
	
	// {
	// 	Bureaucrat br1("Marko", 1);

	// 	br1.incr_grade();
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Suzana", 149);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	// 	br1.decr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	

	// {
	// 	Bureaucrat br1("Peter", 150);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Emanuel", 151);

	// 	br1.decr_grade();
	// 	std::cout << br1;
	// 	br1.incr_grade();
	// 	std::cout << br1;
	
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	// {
	// 	Bureaucrat br1("Lidia", 33);

	// 	br1.setGrade(177);
	// 	std::cout << br1;
	// 	br1.setGrade(-99);
	// 	std::cout << br1;
	// 	br1.setGrade(50);
	// 	std::cout << br1;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


    // {
	// 	// SHALL IT COPY, IF GRADE IS OUT OF RANGE, OR REFUSE TO COPY ???
	// 	Bureaucrat br1("Jordan", 999);

    //     Bureaucrat br2(br1);
    //     // Bureaucrat br2 = br1;
    //     // br2 = br1;
		
	// 	std::cout << br1;
	// 	std::cout << br2;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	//   {
	// 	// SHALL IT COPY, IF GRADE IS OUT OF RANGE, OR REFUSE TO COPY ???
	// 	Bureaucrat br1("Jordan", 200);
	// 	std::cout << br1;


    //     // Bureaucrat br2(br1);
    //     // // Bureaucrat br2 = br1;
    //     // // br2 = br1;
		
	// 	// std::cout << br1;
	// 	// std::cout << br2;
	// }	
	// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	//system("leaks a.out");
	return 0;
}









