/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:59:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/30 11:10:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"




template <typename T, typename Container>
void printAllElements( MutantStack<T, Container> &ms)
{
	typename MutantStack<T, Container>::myIterator it;
	it = ms.myBegin();
	std::cout << "Print all elements:   ";
	for (unsigned int i = 0; i < ms.size(); i++)
		std::cout << BLU" " << *(it++) << " " RES;
	std::cout << "\n";
}



int main()
{
	{
		std::cout << "Test STACK with INTS - - - - - - - - - - - - - - - \n\n";
		MutantStack<int> ms;

		for (int i = 1; i < 6; i++)
			ms.push(i * 10);
		
		std::cout << "myBegin:    " << *(ms.myBegin()) << "\n";
		std::cout << "myEnd:      " << *(ms.myEnd() - 1) << "\n";
		std::cout << "ms.top():   " << ms.top() << "\n";
		std::cout << "Stack size: " << ms.size() << "\n";

		printAllElements(ms);

		MutantStack<int>::myIterator it1 = ms.myBegin();
		std::cout << "    it1: " << *it1 << "\n";

		std::deque<int>::iterator it2 = ms.myBegin();
		std::cout << "     it2: " << *it2 << "\n";
		
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";



	{
		std::cout << "Test STACK with FLOATS - - - - - - - - - - - - - - - \n\n";
		MutantStack<float> ms;

		for (int i = 1; i < 6; i++)
			ms.push((float)(i * 10.3));
		
		std::cout << "myBegin:    " << *(ms.myBegin()) << "\n";
		std::cout << "myEnd:      " << *(ms.myEnd() - 1) << "\n";
		std::cout << "ms.top():   " << ms.top() << "\n";
		std::cout << "Stack size: " << ms.size() << "\n";

		printAllElements(ms);
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";


	{
		std::cout << "Test STACK with CHARS - - - - - - - - - - - - - - - \n\n";
		MutantStack<char> ms;

		for (int i = 0; i < 5; i++)
			ms.push('A' + i);
		
		std::cout << "myBegin:    " << *(ms.myBegin()) << "\n";
		std::cout << "myEnd:      " << *(ms.myEnd() - 1) << "\n";
		std::cout << "ms.top():   " << ms.top() << "\n";
		std::cout << "Stack size: " << ms.size() << "\n";

		printAllElements(ms);
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";



	{
		std::cout << "Test STACK with STRINGS - - - - - - - - - - - - - - - \n\n";
		MutantStack<std::string> ms;

		ms.push("Jaka");
		ms.push("Daniel");
		ms.push("Irene");
		ms.push("Nina");
		ms.push("Natasha");
		
		std::cout << "myBegin:    " << *(ms.myBegin()) << "\n";
		std::cout << "myEnd:      " << *(ms.myEnd() - 1) << "\n";
		std::cout << "ms.top():   " << ms.top() << "\n";
		std::cout << "Stack size: " << ms.size() << "\n";

		printAllElements(ms);
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";
	


	{
		std::cout << "Test COPY CONSTR. AND OVERLOAD= - - - - - - - - - - - - - - - \n\n";
		MutantStack<char> ms;

		for (int i = 0; i < 5; i++)
			ms.push('A' + i);
		
		MutantStack<char> ms2(ms);
		// MutantStack<char> ms2 = ms;
		//MutantStack<char> ms2;
		//ms2 = ms;

		ms.push('X');

		printAllElements(ms);
		printAllElements(ms2);
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";

	

	
	// Print out the vector // NOT WORKING WITH STACK CONTAINER
	// std::cout << "v = { ";
	// for (int n : ms)
	// 	std::cout << n << ", ";
	// std::cout << "}; \n";


	return (0);
}
