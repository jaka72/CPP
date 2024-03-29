/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 18:15:22 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/07 18:16:18 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	// FROM SUBJECT:

	Fixed		a;
	Fixed const	b( 10 );
	Fixed const	c( 42.42f );
	Fixed const	 d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "\n";
	std::cout << "a is " << a << "\n";
	std::cout << "b is " << b << '\n';
	std::cout << "c is " << c << '\n';
	std::cout << "d is " << d << "\n\n";
	
	std::cout << "a is " << std::setw(6) << a.toInt() << " as integer\n";
	std::cout << "b is " << std::setw(6) << b.toInt() << " as integer\n";
	std::cout << "c is " << std::setw(6) << c.toInt() << " as integer\n";
	std::cout << "d is " << std::setw(6) << d.toInt() << " as integer\n\n";



//////////////////////////////////////////////////////////////////////////////

	// MORE TESTS
	// Fixed const x0( 5.0f );
	// std::cout << "x0 is " << std::setw(6) << x0.toInt() << " as integer\n";
	// std::cout << "x0 is " << std::setw(6) << x0.toFloat() << " as float\n\n";

	// Fixed const x1( 0.5f );
	// std::cout << "x1 is " << std::setw(6) << x1.toInt() << " as integer\n";
	// std::cout << "x1 is " << std::setw(6) << x1.toFloat() << " as float\n\n";

	// Fixed const x2( 0.05f );
	// std::cout << "x2 is " << std::setw(6) << x2.toInt() << " as integer\n";
	// std::cout << "x2 is " << std::setw(6) << x2.toFloat() << " as float\n\n";

	// Fixed const x3( 0.005f );
	// std::cout << "x3 is " << std::setw(6) << x3.toInt() << " as integer\n";
	// std::cout << "x3 is " << std::setw(6) << x3.toFloat() << " as float\n\n";

	// Fixed const x4( 0.0005f );
	// std::cout << "x4 is " << std::setw(6) << x4.toInt() << " as integer\n";
	// std::cout << "x4 is " << std::setw(6) << x4.toFloat() << " as float\n\n";

}
