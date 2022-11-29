/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:06 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 12:28:57 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>	// for stack
#include <vector>	// for vector
//#include<iterator>	// apparently not necessary
#include <functional>
#include "colors.h"


template <typename T>
// class MutantStack : public std::stack<T>
class MutantStack : public std::vector<T>
{
	private:
		//

	public:
		typedef std::vector <T>		myStack;
		// typedef typename std::iterator		myIterator2;
		// typedef typename std::iterator<T>		myIterator2;
		typedef typename myStack::iterator		myIterator2;
		
		// WHAT ARE THESE ???
		//	typedef DEFINES A NEW TYPE 'myIterator'
		//	typename informs the compiler, that 'myIterator' is a type (not a member of object myStack)
		//	:: colons are the scope:  iterator is in container_type, which is in stack (parent of myStack)
		//				myStack : stack<T>		inherited : child
		//					container_type						parent
		//							iterator						grandParent
		// https://stackoverflow.com/questions/18385418/c-meaning-of-a-statement-combining-typedef-and-typename
		//typedef typename myStack::container_type::iterator	myIterator;


		// CONSTRUCTORS ONLY WORK IF DEFINITIONS ARE IN .tpp
		//	BUT OTHER FUNCTIONS DONT WORK IF DEFINED IN .tpp OR .cpp ????
		MutantStack();
		MutantStack(const myStack &src);
		~MutantStack();



		// THIS DOES NOT WORK IN CPP OR TPP FILE ???
		myStack &operator= (const myStack &src)
		{
			std::cout << "Overload= (MutantStack)\n";
			(void)src;
			return (*this);
		}



		void test_iterator();		// MOVED TO .tpp file
		// void test_iterator()
		// {
		// 	typename myStack::iterator it;
		// 	it = this->begin();
		// 	std::cout << "test_iterator: " << *it << "\n";
		// }



		//typename MutantStack::iterator myBegin()   // ok
		//typename myStack::iterator myBegin()   	// ok
		myIterator2 myBegin();						// ok if line:  typedef typename myStack::iterator		myIterator2;
		// myIterator2 myBegin()						// ok if line:  typedef typename myStack::iterator		myIterator2;
		// {
		// 	// std::cout << "From myBegin: " << *(this->begin()) << ", ";		// OK
		// 	std::cout << "From myBegin: " << *(myStack::begin()) << ", ";		// OK
		// 	//return (myStack::c.begin());	// NO
			
		// 	return (myStack::begin());		// OK
		// 	// return (this->begin());			// OK
		// }


		myIterator2 myEnd();
		// myStack myEnd()
		// {
		// 	// return (myStack::c.end());
		// 	// return (myStack::end());
		// 	return (end());
		// }


		/*
			Container c  !!!
			Is the underlying container. It is a protected member object of Stack
		*/

};


#include "MutantStack.tpp"

#endif




// myStack &MutantStack::operator= (const myStack &src)
// {
// 	std::cout << "Overload= (MutantStack)\n";
// 	return (*this);
// }



// WHAT IS THIS c.   ???
// template <typename T>

// myIterator MutantStack<T>::begin()
// {
// 	return (myStack::c.begin());
// }



// myIterator MutantStack::end()
// {
// 	return (myStack::c.end());
// }
