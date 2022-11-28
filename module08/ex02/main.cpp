/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 16:59:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/27 21:10:01 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/*
	ISSUE in .hpp and .cpp
	It only works if all definitions of constructs are in the header, which I think 
	is not allowed by subject.
	If I move definitions to .cpp, it says error "undefined reference to MutantStack<int>::MutantStack()"

*/



int main()
{
	MutantStack<int> ms;

	ms.push(11);
	ms.push(22);
	ms.push(33);
	ms.push(44);
	ms.push(55);
	
	std::cout << "First element: " << *(ms.myBegin()) << "\n";
	std::cout << "Last element:  " << *(ms.myEnd() - 1) << "\n";
	std::cout << "top() element: " << ms.top() << "\n";
	std::cout << "stack size:    " << ms.size() << "\n";

	// std::cout << "myEnd() element: " << *(ms.myEnd2()) << "\n";

	
	// Print out the vector // NOT WORKING WITH STACK CONTAINER
	// std::cout << "v = { ";
	// for (int n : ms)
	// 	std::cout << n << ", ";
	// std::cout << "}; \n";


	return (0);
}
