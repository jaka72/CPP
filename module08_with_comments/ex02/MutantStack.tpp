/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 17:00:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/29 15:29:25 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP


#include "MutantStack.hpp"


template <typename T, typename Container>
MutantStack<T, Container> ::MutantStack()	//: myStack()
{
	std::cout << GRE"Default contructor (MutantStack)\n" RES;
}


template <typename T, typename Container>
MutantStack<T, Container> ::MutantStack(const myStack &src) : std::stack<T>(src)
{
	std::cout << GRE"Copy contructor (MutantStack)\n" RES;
	*this = src;
}


template <typename T, typename Container>
MutantStack<T, Container> ::~MutantStack()
{
	std::cout << GRE"Destructor (MutantStack)\n" RES;
}



template <typename T, typename Container>
void MutantStack<T, Container>::printAllElements()
{
	typename MutantStack::myIterator it;
	it = myBegin();
	std::cout << "Print all elements:   ";
	for (unsigned int i = 0; i < this->size(); i++)
		std::cout << BLU" " << *(it++) << " " RES;
	std::cout << "\n";
}




// HOW TO USE THE OVERLOAD=  INSIDE .TPP
// template <typename T>
// MutantStack<T> &MutantStack<T>::operator= (const myStack<T> &src)
// {
// 	std::cout << "Overload= (MutantStack)\n";
// 	return (*this);
// }


//template <typename T, typename Container>
//void MutantStack<T, Container>::test_iterator()
//{	
//	std::cout << BLU"test_iterator, begin " << *(myBegin()) << "\n" RES;
//	std::cout << BLU"test_iterator, end   " << *(myEnd() - 1) << "\n" RES;

	//typename myStack::myIterator it; 


	// it = this->begin();
	//it = myStack::c.begin();
	// std::cout << BLU"test_iterator, begin " << *it << "\n" RES;
	
	// it = this->end() - 1;
	// //it++;
	// std::cout << BLU"test_iterator, end   " << *it << "\n" RES;
//}


#endif
