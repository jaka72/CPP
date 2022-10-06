/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:42:50 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/06 12:42:51 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>   
#include "Fixed.hpp"



int	main()
{
//	TESTS FOR EX02 

	// Fixed const add_int (Fixed(5) + Fixed(2));
	// Fixed const add_float (Fixed(5.3f) + Fixed(2.1f));
	// std::cout << "add_int is " << add_int << '\n';
	// std::cout << "add_float is " << add_float << '\n';
	
	// Fixed const sub_int (Fixed(2) - Fixed(5));
	// Fixed const sub_float (Fixed(2.1f) - Fixed(5.6f));
	// std::cout << "sub_int is " << sub_int << '\n';
	// std::cout << "sub_float is " << sub_float << '\n';
	
	// Fixed const mul_int (Fixed(5.05f) * Fixed(2.1f));
	// Fixed const mul_float (Fixed(5) * Fixed(2));
	// std::cout << "mul_int is " << mul_int << '\n';
	// std::cout << "mul_float is " << mul_float << '\n';

	// INT / FLOAT
	// Fixed const mul_int (Fixed(5) * Fixed(2.1f));
	// Fixed const mul_float (Fixed(5) * Fixed(2));
	// std::cout << "mul_int is " << mul_int << '\n';
	// std::cout << "mul_float is " << mul_float << '\n';

	// Fixed const div_int (Fixed(12) / Fixed(3));
	// Fixed const div_float (Fixed(10.0f) / Fixed(4.0f));
	// std::cout << "div_int is " << div_int << '\n';
	// std::cout << "div_float is " << div_float << '\n';
	
	std::cout << "\n";


	// COMPARISSON
	// Fixed x{33};
	// Fixed y{44};
	// std::cout << "Is less: " << (y < x) << "  :isless\n";


//////////////////////////////////////////////////////////////////////////////


//Fixed b( a );	// ALSO OK: Fixed b = a
// //	Fixed b { a };	// Is it ok?
// 	Fixed c;
// 	c = b;

// 	std::cout << a.getRawBits() << '\n';
// 	std::cout << b.getRawBits() << '\n';
// 	std::cout << c.getRawBits() << '\n';
	

	std::cout << "\n";



	// Fixed x{ 0 };
	//std::cout << "Increments:  " << x++ << "  ==>end \n";
	//std::cout << "Increments:  " << x << "  ==>end \n";

	// Fixed a;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// Fixed w{33};
	// Fixed q{88};

	// std::cout << "min:  " << Fixed::min(w, q) << " :min \n";


	// FROM SUBJECT EX02
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c(22);


	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

// OTHER TESTS ///////////////////////////////

	std::cout << Fixed::max( a, c ) << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;

// OTHER TESTS ///////////////////////////////
	// a.setRawBits(33);
	// c.setRawBits(77);
	// std::cout << "Value fpn: " << a <<"\n";
	// std::cout << "Value fpn: " << c <<"\n";


	// Fixed x_const (Fixed::min(a, c));
	// std::cout << "Value x_const: " << x_const <<"\n";
	// x_const.setRawBits(33);

	// Fixed aaa (Fixed::min(a,b));




}
