/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/01 11:17:23 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main()
{
	Fixed a;		// Calling default constructor


	Fixed b( a );	//	Calling copy constructor	
//	Fixed b { a };	// 		ALSO OK: Fixed b = a
					// 		Is it ok? Only c++11


	Fixed c;
	c = b;	// Calling copy assignemnt overload


	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';
	
	c.setRawBits(77);
	std::cout << c.getRawBits() << '\n';

}
