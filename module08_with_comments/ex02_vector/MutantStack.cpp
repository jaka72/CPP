/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 12:17:41 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


// template <typename T>
// MutantStack<T> ::MutantStack()	//: myStack()
// {
// 	std::cout << "Default contructor (MutantStack)\n";
// }

// template <typename T>
// MutantStack<T> ::MutantStack(const myStack &src)
// {
// 	std::cout << "Copy contructor (MutantStack)\n";
// 	*this = src;
// }

// template <typename T>
// MutantStack<T> ::~MutantStack()
// {
// 	std::cout << "Destructor (MutantStack)\n";
// }



// // OVERLOAD=
// // HOW TO CORRECTLY DEFINE OVERLOAD= HERE IN TPP
// // template <typename T>
// // MutantStack<T> &MutantStack<T>::operator= (const myStack<T> &src)
// // {
// // 	std::cout << "Overload= (MutantStack)\n";
// // 	return (*this);
// // }






// // MEMBER FUNCTIONS ////////////////////////////////////////

// // MYBEGIN
// template <typename T>
// typename MutantStack<T>::myIterator2 MutantStack<T>::myBegin()
// {
// 	std::cout << "From myBegin: " << *(MutantStack<T>::begin()) << "\n";
// 	//return (myStack::c.begin());	// NO
	
// 	return (MutantStack<T>::begin());		// OK
// 	// return (this->begin());				// OK
// }


// template <typename T>
// typename MutantStack<T>::myIterator2 MutantStack<T>::myEnd()
// {
// 	std::cout << "From myBegin: " << *(MutantStack<T>::begin()) << "\n";

// 	// return (myStack::c.end());
// 	// return (myStack::end());
// 	return (MutantStack<T>::end());
// }




// template <typename T>
// void MutantStack<T>::test_iterator()
// {
// 	typename myStack::iterator it;
// 	it = this->begin();
// 	std::cout << "test_iterator, begin " << *it << "\n";
// 	it = this->end() - 1;
// 	//it++;
// 	std::cout << "test_iterator, end   " << *it << "\n";
// }
