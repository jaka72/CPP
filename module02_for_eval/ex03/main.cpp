/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 13:26:55 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/07 18:26:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>   
#include "Fixed.hpp"
#include "Point.hpp"

int	main()
{
	std::cout << "Constructing points: \n\n";

	Point a(0,  0);
	std::cout << "   Point a:    x=" << a.get_x() << ", y=" << a.get_y()<< "\n";
	Point b(20, 5);
	std::cout << "   Point b:    x=" << b.get_x() << ", y=" << b.get_y()<< "\n";
	Point c(10, 30);
	std::cout << "   Point c:    x=" << c.get_x() << ", y=" << c.get_y()<< "\n";
	Point p(10, 15);
	std::cout << "   Point p:    x=" << p.get_x() << ", y=" << p.get_y()<< "\n";
	
	float area = a.area(a, b, c);
	std::cout << "   Area(a, b, c)   = " << area << "\n";

	// ALSO POSSIBLE
	// Fixed a1(44);
	// Fixed a2(77);
	// Point x2(a1.toFloat(), a2.toFloat());
	// std::cout << "   Point x2(11, 33):    x=" << x2.get_x() << ", y=" << x2.get_y()<< "\n";
	

	std::cout << "\n\n --- CHECK POINT IN A TRIANGLE -------------------- \n\n";

	if (p.bsp(a, b, c, p) == true)
		std::cout << "\nIt is inside.\n\n";
	else
		std::cout << "\nIt is NOT inside.\n\n";

}
