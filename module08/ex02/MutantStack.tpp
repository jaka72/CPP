/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/27 18:40:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP


#include "MutantStack.hpp"


template <typename T>
MutantStack<T> ::MutantStack()	//: myStack()
{
	std::cout << "Default contructor (MutantStack)\n";
}

template <typename T>
MutantStack<T> ::MutantStack(const myStack &src)
{
	std::cout << "Copy contructor (MutantStack)\n";
	*this = src;
}

template <typename T>
MutantStack<T> ::~MutantStack()
{
	std::cout << "Destructor (MutantStack)\n";
}




// template <typename T>
// MutantStack<T> &MutantStack<T>::operator= (const myStack<T> &src)
// {
// 	std::cout << "Overload= (MutantStack)\n";
// 	return (*this);
// }


// // WHAT IS THIS c.   ???
// template <typename T>
// myIterator MutantStack<T>::myBegin()
// {
// 	return (myStack::c.begin());
// }


// template <typename T>

// myIterator<T> MutantStack::myEnd()
// {
// 	return (myStack::c.end());
// }


#endif
