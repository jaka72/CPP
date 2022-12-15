/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:22:28 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/15 15:10:08 by jmurovec      ########   odam.nl         */
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


// Getters
unsigned int Span::getCurrentNrElements()
{
	std::cout << "Container now has " << _vect.size() << " elements (of max " << _size << ")\n";
	return (_vect.size());
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
	//std::cout << "addnumber, new size: " << _vect.size() << "\n";
}




// VERSION WITH ALGORITHM 'adjacent_difference'
unsigned int Span::shortestSpanAD()
{
	std::cout << GRN"Shortest Span AD: " RES;
	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}

	std::sort(_vect.begin(), _vect.end());

	// The problem is, that this function always measures from 0 to the first element.
	// If this value is smaller than any other pair distance, it will be later detected
	// as the smallest distance, which is wrong.
	// But then, the calculate differencies are put back into the same array, so you 
	// get same number of elements, instead of one less.
	
	std::adjacent_difference (_vect.begin(), _vect.end(), _vect.begin());

	int min = *min_element(_vect.begin() + 1, _vect.end());
	std::cout << GRN << min << "\n" RES;
	return (min);
}



// VERSION WITHOUT ALGORITHM AND WITHOUT ITERATOR
unsigned int Span::shortestSpan()
{
	std::cout << GRN"Shortest Span:    " RES;
	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}
	
	std::sort(_vect.begin(), _vect.end());

	unsigned int i = 0;
	int span = *(_vect.begin() + 1) - *(_vect.begin());
	i++;
	for (  ; i < _vect.size() - 1; i++)
	{
		if ( span > (*(_vect.begin() + i+1)) - (*(_vect.begin() + i)))
			span = (*(_vect.begin() + (i+1))) - (*(_vect.begin() + i));
	}
	std::cout << GRN << span << "\n" RES;
	return (span);
}





// VERSION WITH ITERATOR
unsigned int Span::shortestSpanIT()
{
	std::cout << GRN"Shortest Span IT: " RES;
	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}
	std::sort(_vect.begin(), _vect.end());

	std::vector<int>::iterator itPrev = _vect.begin();
	std::vector<int>::iterator itNext = _vect.begin() + 1;

	int span = *itNext - *itPrev;
	for ( ;  itNext != _vect.end() ; )
	{
		if (span > (*itNext - *itPrev))
			span = (*itNext - *itPrev);
		itPrev++;
		itNext++;
	}
	std::cout << GRN << span << "\n" RES;
	return (span);
}





unsigned int Span::longestSpan()
{
	std::cout << GRN"Longest Span:  " RES;

	if (_vect.size() <= 1)
	{
		std::cout << LRD << "Cannot compare 0 or 1 element.\n";
		throw (std::exception());
	}
	std::sort(_vect.begin(), _vect.end());

	// 								largest				smallest
	unsigned int longestSpan = *(_vect.end() - 1) - *(_vect.begin());

	std::cout << GRN"" <<  longestSpan << "\n" RES;
	return (longestSpan);
}




static int getRandomNumber(void)
{
	return (rand());
}


/* Creates N random numbers, stored into vector Temp,
	then inserts Temp into original Vector sp	*/
void Span::fillWithRandom(Span* sp, unsigned int N)
{
	if (N > sp->getSize())
		throw std::out_of_range("fillWithRandom: Cannot add, the vector is smaller than N\n");
	std::vector<int> temp(N);
	std::generate_n(temp.begin(), N, getRandomNumber);
	//std::cout << temp[0] << "\n";
	sp->_vect.insert(sp->_vect.begin(), temp.begin(), temp.end() );
}





// EXCEPTIONS /////////////////////////////////////

// THIS MUST NOT BE IN class.hpp, BUT IN class.cpp
const char* Span::SpanExceptions::what() const throw()
{
	return ("(Exception from Span)\n");
}
