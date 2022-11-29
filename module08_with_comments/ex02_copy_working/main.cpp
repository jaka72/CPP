/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:59:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 13:21:35 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
	ISSUE in .hpp and .cpp
	It only works if all definitions of constructs are in the header,
	which I think is not allowed by subject.
	But templates are allowed in the .hpp?
	If I move definitions to .cpp, it says error "undefined reference to MutantStack<int>::MutantStack()"
*/



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

		//ms.test_iterator();
		ms.printAllElements();

		MutantStack<int>::myIterator it = ms.myBegin();
		std::cout << "     main, it: " << *it << "\n";
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

		//ms.test_iterator();
		ms.printAllElements();

		MutantStack<float>::myIterator it = ms.myBegin();
		std::cout << "     main, it: " << *it << "\n";
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

		//ms.test_iterator();
		ms.printAllElements();


		MutantStack<char>::myIterator it = ms.myBegin();
		std::cout << "     main, it: " << *it << "\n";
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

		//ms.test_iterator();

		MutantStack<std::string>::myIterator it = ms.myBegin();
		std::cout << "     main, it: " << *it << "\n";

		ms.printAllElements();

		// std::cout << "myEnd() element: " << *(ms.myEnd2()) << "\n";

	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - \n\n\n";
	
	// Print out the vector // NOT WORKING WITH STACK CONTAINER
	// std::cout << "v = { ";
	// for (int n : ms)
	// 	std::cout << n << ", ";
	// std::cout << "}; \n";


	return (0);
}
