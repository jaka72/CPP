/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 11:17:22 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/06 12:06:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/* Questions:

	Why is it called 'raw bits'?  (If it is simply an integer?)

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
	
	c.setRawBits(123);
	std::cout << c.getRawBits() << '\n';

}
