/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 11:23:42 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/27 16:45:35 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int main()
{
	// creation of a string stack
	MutantStack<std::string> myStackStr;
	myStackStr.push("Beer");
	myStackStr.push("Cola");
	myStackStr.pop();
	myStackStr.push("Rum");
	myStackStr.push("Vodka Smirnoff");
	std::cout << std::endl << std::endl << "↓↓↓ String Stack Information ↓↓↓\nSize: " << myStackStr.size() << "\nEmpty: " << (myStackStr.empty() ? "true" : "false") << std::endl;


	// creation of a int stack
	MutantStack<int> myStackInt;
	myStackInt.push(5);		// addding 5
	myStackInt.push(17);	// adding 17
	myStackInt.pop();		// deleting 17
	myStackInt.push(3);		// adding 3
	myStackInt.push(737);	// adding 737

	std::cout << std::endl;

	// start working with string stack ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	MutantStack<std::string>::myIter s_it = myStackStr.begin();
	MutantStack<std::string>::myIter e_it = myStackStr.end();

	//++s_it;
	//--s_it;
	std::cout << "String Iterator: ";
	while (s_it != e_it)
	{
		std::cout << *s_it << ", ";
		++s_it;
	}

	std::cout << std::endl << std::endl << "↓↓↓ String Stack Information ↓↓↓\nSize: " << myStackStr.size() << "\nEmpty: " << (myStackStr.empty() ? "true" : "false") << std::endl;
	myStackStr.pop();
	myStackStr.pop();
	myStackStr.pop();
	std::cout << std::endl << std::endl << "↓↓↓ String Stack Information ↓↓↓\nSize: " << myStackStr.size() << "\nEmpty: " << (myStackStr.empty() ? "true" : "false") << std::endl;
	// end working with string stack ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

	std::cout << std::endl << "-------------------------------------------------------------------" << std::endl << std::endl;







	// start working with int stack ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
	MutantStack<int>::myIter it_s = myStackInt.begin();
	MutantStack<int>::myIter it_e = myStackInt.end();

	++it_s;
	--it_s;

	std::cout << "Int Iterator: ";
	while (it_s != it_e)
	{
		std::cout << *it_s << "` ";
		++it_s;
	}

	std::cout << std::endl << std::endl << "↓↓↓ Int Stack Information ↓↓↓\nSize: " << myStackInt.size() << "\nEmpty: " << (myStackInt.empty() ? "true" : "false") << std::endl << std::endl;
	// end working with int stack ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

	return 0;
}
