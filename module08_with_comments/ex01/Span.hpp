/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 17:22:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/28 16:43:26 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include "colors.h"

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_vect;
		Span();						// should not be called, does not init. the size

	public:
		Span(unsigned int N);
		Span(const Span &src);

		Span &operator= (const Span &src);
		~Span();

		// Getters
		unsigned int		getSize() const;
		std::vector<int>	getVect() const;
		unsigned int		getCurrentNrElements();
		void 				printContainerInfo2(); // ON MAC NOT PRINTING CORRECT 




		// Public member functions
		void			addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int 	shortestSpanIT();

		unsigned int	longestSpan();
		//void			printElements();


		class SpanExceptions : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};



#endif
