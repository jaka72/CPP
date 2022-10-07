/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 10:34:11 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 13:32:56 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



int	main()
{
	std::cout << "--- Tests from the subject Ex02 -------------------------\n";

	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << "\n\n";



// OTHER TESTS ///////////////////////////////

	Fixed x(4);
	Fixed y(8);
	
	std::cout << "--- Arithmetic operators -------------------------------\n";
	std::cout << "    add:       " << x << " + " << y << " = " << x + y << "\n";
	std::cout << "    substract: " << x << " - " << y << " = " << x - y << "\n";
	std::cout << "    multiply:  " << x << " * " << y << " = " << x * y << "\n";
	std::cout << "    divide:    " << x << " / " << y << " = " << x / y << "\n\n";


	std::cout << "--- Comparisson operators ------------------------------\n";
	std::cout << "    " << x << " < " << y << "     = " << (x < y) << "\n";
	std::cout << "    " << x << " > " << y << "     = " << (x > y) << "\n";
	std::cout << "    " << x << " >= " << y << "    = " << (x >= y) << "\n";
	std::cout << "    " << x << " <= " << y << "    = " << (x <= y) << "\n";
	std::cout << "    " << x << " == " << y << "    = " << (x == y) << "\n";
	std::cout << "    " << x << " != " << y << "    = " << (x != y) << "\n\n";


	std::cout << "--- Increment operators ------------------------------\n";
	std::cout << "            x = " << x << "\n";
	std::cout << "    ++x     x = " << ++x << "\n";
	std::cout << "            x = " << x << "\n";
	std::cout << "    x++     x = " << x++ << "\n";
	std::cout << "            x = " << x << "\n\n";

	std::cout << "            x = " << x << "\n";
	std::cout << "    --x     x = " << --x << "\n";
	std::cout << "            x = " << x << "\n";
	std::cout << "    x--     x = " << x-- << "\n";
	std::cout << "            x = " << x << "\n\n";


	std::cout << "--- Min and Max functions ----------------------------\n";
	std::cout << Fixed::max( x, y ) << "\n";
	std::cout << Fixed::min( x, y ) << "\n";

	Fixed const c1(22);
	Fixed const	c2(33);
	std::cout << Fixed::min( c1, c2 ) << "\n";
	std::cout << Fixed::max( c1, c2 ) << "\n\n";


	std::cout << "     c1.min(c1, c2)" << c1.min(c1, c2) << "\n";
	std::cout << "     c1.max(c1, c2)" << c1.max(c1, c2) << "\n\n";


	// More different tests /////////////////////////////////////////
	
	// Fixed test;
	// test = (Fixed(2) - Fixed(5));
	// std::cout << "   result: " << test << '\n';
	
	// test = (Fixed(2.1f) - Fixed(5.6f));
	// std::cout << "   result: " << test << '\n';
	
	// std::cout << "    multiply:  " << x << " * " << y << " = " << x * y << "\n";
	// std::cout << "    divide:  " << x << " / " << y << " = " << x / y << "\n";



	// TESTING - LOSING PRECISION ///////////////////////////////////////////
	// std::cout << "LOSING PRECISION:\n";
	// Fixed const x0( 5.0f );
	// std::cout << "x0 as fpn: " << x0.getRawBits() << "\n";
	// std::cout << "x0 is " << std::setw(6) << x0.toInt() << " as integer\n";
	// std::cout << "x0 is " << std::setw(6) << x0.toFloat() << " as float\n\n";

	// Fixed const x1( 0.5f );
	// std::cout << "x1 as fpn: " << x1.getRawBits() << "\n";
	// std::cout << "x1 is " << std::setw(6) << x1.toInt() << " as integer\n";
	// std::cout << "x1 is " << std::setw(6) << x1.toFloat() << " as float\n\n";

	// Fixed const x2( 0.05f );
	// std::cout << "x2 as fpn: " << x2.getRawBits() << "\n";
	// std::cout << "x2 is " << std::setw(6) << x2.toInt() << " as integer\n";
	// std::cout << "x2 is " << std::setw(6) << x2.toFloat() << " as float\n\n";

	// Fixed const x3( 0.005f );
	// std::cout << "x3 as fpn: " << x3.getRawBits() << "\n";
	// std::cout << "x3 is " << std::setw(6) << x3.toInt() << " as integer\n";
	// std::cout << "x3 is " << std::setw(6) << x3.toFloat() << " as float\n\n";

	// Fixed const x4( 0.0005f );
	// std::cout << "x4 as fpn: " << x4.getRawBits() << "\n";
	// std::cout << "x4 is " << std::setw(6) << x4.toInt() << " as integer\n";
	// std::cout << "x4 is " << std::setw(6) << x4.toFloat() << " as float\n\n";

}
