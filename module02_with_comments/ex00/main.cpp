/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:10:31 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


/*
	Converter
	www.rfwireless-world.com/calculators/floating-vs-fixed-point-converter.html

	Computer science, Binary 3
	www.youtube.com/watch?v=QFlbvSeBkwY
*/

/*
	Speed is more important than accuracy, ie. in real time systems.
	It is used in specific devices (in Digital Signal Processing), where
	the processor is simpler and cheaper.
	Arithmetic is thus simplified and much faster.
	The notional (imaginary position) of the binary point in a 'register' was 
	decided, fixed by the designers of a specific device. It can't be moved. Like:
		8 bits before the point, and 4 bits after it.  01001000.1100

	So, the binary point is fixed inside a fixed-size register.
		ie:		6 bits     2 bits
					011010.11

			0	1	1	0	1	1	.	1	 1
				16	+8		+2	+1		+0.5 +0.25	= 26.75
			
			Now move the point to the right 2x
				0110 1111	=	107

	Information that you can have, ie: 
		decimal number 27.5, converted to fixed point binary,
		stored in a 12 bit register
		with 4 bits after the binary point

	Number of places before and after the binary point, means range and precision.
	The bigger range means larger values are possible, but smaller precision, and vice versa. 
*/


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
	Fixed a;		// Calling default constructor


	Fixed b( a );	//	Calling copy constructor	
					// 		Is it ok? Only c++11

	// Fixed c;
	// c = b;	// Calling copy assignemnt overload


	a.setRawBits(44.77);


	std::cout << a.getRawBits() << '\n';
//	std::cout << b.getRawBits() << '\n';
	// std::cout << c.getRawBits() << '\n';
	
	// c.setRawBits(77);
	// std::cout << c.getRawBits() << '\n';



	
//	Fixed e;		// CALLS DEFAULT CONSTR
//	Fixed d();		// WHY THIS DOES NOTHING (NO DEFAULT CONSTR. CALLED) ???
//	Fixed e =d;		// Copy constr called
//	Fixed f { a };	// OK, only from c++11

	int x =	4294967295; // max value
	int y = 2 * x;		// y overflows to -2
	std::cout << sizeof(x) << ", "<< y << ", " << sizeof(y) << "\n";

}
