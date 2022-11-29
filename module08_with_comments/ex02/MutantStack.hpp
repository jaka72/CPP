/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:06 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 15:27:28 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <functional>
#include "colors.h"


template <typename T,
		  typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
		//

	public:
		typedef std::stack<T>					myStack;
		typedef typename Container::iterator	myIterator;
		// typedef typename std::deque<T>::iterator	myIterator;
		// typedef typename myStack::container_type::iterator	myIterator;

	MutantStack()
	{
		std::cout << GRE"Default contructor (MutantStack)\n" RES;
	}

	MutantStack(const myStack &src) : std::stack<T>(src)
	{
		std::cout << GRE"Copy contructor (MutantStack)\n" RES;
		*this = src;
	}
	~MutantStack()
	{
		std::cout << GRE"Destructor (MutantStack)\n" RES;
	}

	myStack &operator= (const myStack &src)
	{
		std::cout << "Overload= (MutantStack)\n";
		//(void)src;
		myStack::operator=(src);
		return (*this);
	}

	myIterator myBegin()
	{
		// return (this->c.begin());
		return (myStack::c.begin());
	}

	myIterator myEnd()
	{
		// return (this->c.end());
		return (myStack::c.end());
	}

	
	//void printAllElements();
	// void test_iterator();
};


//#include "MutantStack.tpp"

#endif
