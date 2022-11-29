/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 11:08:37 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/27 17:05:59 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

// template <class T>
template <typename T>

class MutantStack : public std::stack <T>
{
	public:
		typedef std::stack<T>								myStack;
		typedef typename myStack::container_type::iterator	myIter;
		// typedef typename myStack::container_type	myCont;
		// typedef typename myCont::iterator 			myIter;

		// Constructors
		MutantStack() //: myStack() // IS THIS NECESSARY ???
		{
			std::cout << "Default Constructor called" << std::endl;
		}

		MutantStack(const myStack &src) : myStack(src)
		{
			std::cout << "Copy Constructor called" << std::endl;
		}

		// Deconstuctor
		~MutantStack()
		{
			std::cout << "Deconstuctor called" << std::endl;
		}

		// Overloaded opperators
		myStack &operator=(const myStack &src)
		{
			if (*this != src)
				*this = src;
			return (*this);
		}

		// begin iterator
		myIter begin()
		{
			return (myStack::c.begin());
		}

		// end iterator
		myIter end()
		{
			return (myStack::c.end());
		}
};
