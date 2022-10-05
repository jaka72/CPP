/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/05 18:34:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/* Questions:

	Why is it called 'raw bits'?  (If it is simply an integer?)

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
