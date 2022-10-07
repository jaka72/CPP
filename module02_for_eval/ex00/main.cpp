/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:13:23 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


int	main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;	// Calling copy assignemnt overload

	std::cout << a.getRawBits() << '\n';
	std::cout << b.getRawBits() << '\n';
	std::cout << c.getRawBits() << '\n';
	

	// SOME MORE TESTS ///////////////////////////////
	// c.setRawBits(77);
	// std::cout << c.getRawBits() << '\n';


	// std::cout << "\nTEST BINARY POINT SHIFTING\n\n";
	// int y, x = 53;
	// y = x << 1;
	// std::cout << y << "\n";
	// 	y = x << 2;
	// std::cout << y << "\n";
	// 	y = x >> 1;
	// std::cout << y << "\n";
}
