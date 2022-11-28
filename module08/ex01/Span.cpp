/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:22:28 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/27 21:16:43 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{	
	std::cout << GRE"Default constructor (Span)\n" RES;
}


Span::Span(unsigned int N) : _size(N)
{
	std::cout << GRE"Param. constructor (Span), size " << _size << "\n" RES;
}


Span::Span(const Span &src)
{
	*this = src;
}


Span &Span::operator= (const Span &src)
{
	if (this == &src)
		return (*this);
	
	this->_size = src._size;
	return (*this);
}


Span::~Span()
{	}


// Getters
unsigned int Span::getSize() const
{
	return (_size);
}


std::vector<int> Span::getVect() const
{
	return (_vect);
}



// Public member functions

void Span::addNumber(int n)
{
	if (_vect.size() == _size)
	{
		std::cerr << LRD"Cannot add element, max size is reached.\n" RES;
		throw (std::exception());
	}
	_vect.push_back(n);
}



unsigned int Span::shortestSpan()
{
	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}
	
	std::sort(_vect.begin(), _vect.end());

	unsigned int i = 0;
	int span = *(_vect.begin() + 1) - *(_vect.begin());
	std::cout << BLU"        begin +1: " << *(_vect.begin() + i + 1) << ",   begin: " << *(_vect.begin() + i) << "\n" RES;
	std::cout << GRN"Shortest span a) " << span << "\n" RES;
	i++;
	// for (  ; i < _size - 1; i++)
	for (  ; i < _vect.size() - 1; i++)
	{
		if ( span > (*(_vect.begin() + i+1)) - (*(_vect.begin() + i)))
			span = (*(_vect.begin() + (i+1))) - (*(_vect.begin() + i));
		std::cout << BLU"        begin+i+1: " << *(_vect.begin() + i + 1) << ",   begin+i: " << *(_vect.begin() + i) << "\n" RES;
	}
	std::cout << GRN"Shortest span: END " << span << "\n" RES;
	return (0);
}




unsigned int Span::longestSpan()
{
	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}


	// max_elem() is maybe not in c98 ???
	//std::vector<int>::iterator it_largest = max_element(vect.begin(), vect.end());

	//std::cout << "Before, first elem: " <<  *(_vect.begin()) << "\n";
	//std::cout << "Before, last  elem: " <<  *(_vect.end() - 1) << "\n";
	std::sort(_vect.begin(), _vect.end());
	std::cout << "Sorted, first elem: " <<  *(_vect.begin()) << "\n";
	std::cout << "Sorted, last  elem: " <<  *(_vect.end() - 1) << "\n";

	// 								largest				smallest
	unsigned int longestSpan = *(_vect.end() - 1) - *(_vect.begin());

	std::cout << GRN"Longest  span: " <<  longestSpan << "\n" RES;

	return (longestSpan);
}






// EXCEPTIONS /////////////////////////////////////

// THIS MUST NOT BE IN class.hpp, BUT IN class.cpp
const char* Span::SpanExceptions::what() const throw()
{
	return ("(Exception from Span)\n");
}
