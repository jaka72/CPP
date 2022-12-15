/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:39:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/15 15:02:48 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "Span.hpp"



void printElements(std::vector<int> vect)
{
	std::cout << "Print elements: ";
	if (vect.empty())
	{
		std::cout << "Nothing to print, container is empty\n";
		return ;
	}
	unsigned int i;
	unsigned int size = vect.size();
	for (i = 0; i < size; i++)
	{
		std::cout << *(vect.begin() + i) << " ";
	}
	std::cout << "\n";
}


// OLD
// void fillWithRandom(Span& sp)
// {	
// 	std::cout << GRE"Adding " << sp.getSize() << " random numbers ...\n" RES;

// 	unsigned int i;
// 	for (i = 0; i < sp.getSize(); i++)
// 		//sp.addNumber(rand() % 10000000 );  // max 9.999.999
// 		sp.addNumber(rand());
// }







int main()
{
	std::srand(std::time(0));
	
	{
		std::cout << YEL "\nTest: Empty container - - - - - - - - - - - - - - - - \n\n" RES;
		Span sp1(0);
		// Span sp1(1);

		try
		{
			sp1.getCurrentNrElements();
			sp1.addNumber(33);
			sp1.getCurrentNrElements();
			printElements(sp1.getVect());
		}
		catch(const std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
		}
		
		try
		{
			sp1.longestSpan();
		}
		catch (std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
		}
	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n\n" RES;



	{
		std::cout << YEL "Test: Add 5 numbers - - - - - - - - - - - - - - - - \n\n" RES;

	//	Span sp0;		// called default constr, size is garbage
	//	Span sp0();		// doesnt call any constr, object not created, unusable
		Span sp1(5);			// param. constr.
		Span sp2 = Span(6);		// param. constr.

		printElements(sp2.getVect());

		try
		{
			sp2.getCurrentNrElements();
			sp2.addNumber(6);
			sp2.addNumber(3);
			sp2.addNumber(17);
			sp2.addNumber(9);
			sp2.addNumber(11);


			
			sp2.getCurrentNrElements();
			sp2.addNumber(55);
		}
		catch (const std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
 		}
		
		try
		{
			//sp2.longestSpan();
			printElements(sp2.getVect());
			sp2.shortestSpan();
			sp2.shortestSpanIT();
			sp2.shortestSpanAD();
			//printElements(sp1.getVect());	

		}
		catch(const std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
		}
		

	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n\n" RES;



	{
		std::cout << YEL"Test: Add 10 random numbers - - - - - - - - - - - \n\n" RES;

		srand(time(NULL));
		Span sp1 = Span(5);
		
		try
		{
			sp1.fillWithRandom(&sp1, 5);
			//printElements(sp1.getVect());
			sp1.longestSpan();
			sp1.shortestSpan();
			sp1.shortestSpanIT();
			sp1.shortestSpanAD();
			printElements(sp1.getVect());	
		}
		catch (const std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
 		}
	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n\n" RES;



	{
		std::cout << YEL"Test: Add 20000 random numbers - - - - - - - - - - - \n\n" RES;

		srand(time(NULL));
		Span sp1 = Span(5);
		// Span sp1 = Span(20000);
		
		try
		{
			sp1.fillWithRandom(&sp1, 6);
			//printElements(sp1.getVect());
			sp1.longestSpan();
			sp1.shortestSpan();
			sp1.shortestSpanIT();
			sp1.shortestSpanAD();
		}
		catch(const std::exception& e)
		{
			std::cerr << LRD << e.what() << "\n" RES;
		}
		
	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n\n" RES;

	return (0);
}
