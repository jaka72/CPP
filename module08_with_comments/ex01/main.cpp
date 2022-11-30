/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:39:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/30 11:48:10 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// MAYBE EXIST C++ VERSIONS FOR TIME ???
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Span.hpp"



// ??? HOW TO MAKE THIS WORK WITH ONLY <int>  ,WITHOUT template ???
template <typename T>
void printElements(T vect)
{
	std::cout << "Print elements: ";

	typename T::iterator it;
	for (it = vect.begin(); it != vect.end(); it++ )
	{
		std::cout << "loop ";
		std::cout << *it << " ";
	}
	std::cout << "\n";
}





// void printElements_simple(std::vector<int> vect, unsigned int size)
void printElements_simple(std::vector<int> vect)
{
	std::cout << "Print elements: ";
	if (vect.empty())
	{
		std::cout << "Nothing to print, container is empty\n";
		return ;
	}
	//std::cout << "From printElements_Simple:   ";
	unsigned int i;
	unsigned int size = vect.size();
	for (i = 0; i < size; i++)
	{
		std::cout << *(vect.begin() + i) << " ";
	}
	std::cout << "\n";
}



void fillWithRandom(Span& sp)
{	
	std::cout << GRE"Adding 10000 random numbers ...\n" RES;

	unsigned int i;
	for (i = 0; i < sp.getSize(); i++)
		//sp.addNumber(rand() % 10000000 );  // max 9.999.999
		sp.addNumber(rand());
}



int main()
{
	{
		std::cout << YEL "\n Test: Empty container - - - - - - - - - - - - - - - - \n\n" RES;
		Span sp1(0);
		// sp1.printContainerInfo2();
		sp1.getCurrentNrElements();
	
		printElements_simple(sp1.getVect());
		
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
		Span sp2 = Span(5);		// param. constr.

		printElements_simple(sp2.getVect());

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
		
		sp2.longestSpan();
		printElements_simple(sp2.getVect());
		sp2.shortestSpan();
		sp2.shortestSpanIT();

	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n" RES;


	{
		std::cout << YEL"Test: Add 10 random numbers - - - - - - - - - - - \n\n" RES;

		// time_t seed = time(NULL);
		srand(time(NULL));
		Span sp1 = Span(5);
	
		
		fillWithRandom(sp1);
		sp1.longestSpan();
		sp1.shortestSpan();
		sp1.shortestSpanIT();
		printElements_simple(sp1.getVect());
		
	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n" RES;



	{
		std::cout << YEL"Test: Add 10000 random numbers - - - - - - - - - - - \n\n" RES;

		// time_t seed = time(NULL);
		srand(time(NULL));
		//Span sp1 = Span(5);
		Span sp1 = Span(20000);
	
		
		fillWithRandom(sp1);
		sp1.longestSpan();
		sp1.shortestSpan();
		sp1.shortestSpanIT();
		//printElements_simple(sp1.getVect());
		
	}	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n" RES;





	// {
	// 	std::cout << YEL"Test: Negative integers - - - - - - - - - - - \n\n" RES;

	// 	Span sp1(3);

	// 	sp1.addNumber(1);
	// 	sp1.addNumber(2);
	// 	sp1.addNumber(3);
	// 	//sp1.addNumber(4);
	// 	//sp1.addNumber(5);
	// 	// sp1.addNumber(2);


	// 	printElements_simple(sp1.getVect());
	// 	sp1.longestSpan();
	// 	sp1.shortestSpan();


	// 	printElements(sp1.getVect());
		
		
	// 	// Print out the vector // NOT WORKING WITH STACK CONTAINER
	// 	// std::cout << "v = { ";
	// 	// for (int n : sp1.getVect())	// WORKS WITH VECTOR, BUT ONLY C11
	// 	// 	std::cout << n << ", ";
	// 	// std::cout << "}; \n";
		
	// }	std::cout << YEL"- - -  - - - - - - - - - - - - - - - - - - - - - - -  \n\n" RES;



	// GETTING RANDOM NUMBER FROM TIME /////////
	//time_t t = time(NULL);
	//std::cout << "time t: " << t << "\n";
	//std::cout << "srand(time(NULL)): " << srand(time(NULL)) << "\n";
	//std::cout << "rand(): " << rand() << "\n";



	return (0);
}