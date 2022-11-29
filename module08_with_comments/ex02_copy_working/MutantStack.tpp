/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 13:20:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP


#include "MutantStack.hpp"


template <typename T>
MutantStack<T> ::MutantStack()	//: myStack()
{
	std::cout << GRE"Default contructor (MutantStack)\n" RES;
}

template <typename T>
MutantStack<T> ::MutantStack(const myStack &src)
{
	std::cout << GRE"Copy contructor (MutantStack)\n" RES;
	*this = src;
}

template <typename T>
MutantStack<T> ::~MutantStack()
{
	std::cout << GRE"Destructor (MutantStack)\n" RES;
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

template <typename T>
void MutantStack<T>::test_iterator()
{	
	std::cout << BLU"test_iterator, begin " << *(myBegin()) << "\n" RES;
	std::cout << BLU"test_iterator, end   " << *(myEnd() - 1) << "\n" RES;

	//typename myStack::myIterator it; 


	// it = this->begin();
	//it = myStack::c.begin();
	// std::cout << BLU"test_iterator, begin " << *it << "\n" RES;
	
	// it = this->end() - 1;
	// //it++;
	// std::cout << BLU"test_iterator, end   " << *it << "\n" RES;
}


template <typename T>
void MutantStack<T>::printAllElements()
{
	typename MutantStack::myIterator it;
	it = myBegin();
	std::cout << "Print all elements:   ";
	for (unsigned int i = 0; i < this->size(); i++)
		std::cout << BLU" " << *(it++) << " " RES;
	std::cout << "\n";
}





#endif
