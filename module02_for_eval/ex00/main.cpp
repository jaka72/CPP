/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/06 20:38:12 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/* Questions:

	Why is it called 'raw bits'?  (If it is simply an integer?)

	What is the purpose of this shifting/multiplying by 256 ??
	The only thing I see is that we convert the float to the integer, by 
	multiplying and round it. So it can be used as integer, which is faster 
	than operations with float.
	Why is it not better to just multiply by 10000, so we don't loose that much 
	precision when converting back to float?

	In the document it say, that we need:	width of binary representation, ie: 8
											position of the point
	But in fact, we have:	fpn
							fractional bits = 8

*/


int	main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;	// Calling copy assignemnt overload

	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';
	
	c.setRawBits(77);
	std::cout << c.getRawBits() << '\n';


	std::cout << "\nTEST BINARY POINT SHIFTING\n\n";

	int y, x = 53;
	y = x << 1;
	std::cout << y << "\n";
		y = x << 2;
	std::cout << y << "\n";
		y = x >> 1;
	std::cout << y << "\n";
}
