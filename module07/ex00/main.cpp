/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/24 19:56:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main()
{
	{
		std::cout << BLU"\nSwap two chars:\n" RES;
		char c1 = 'A';
		char c2 = 'B';
		
		std::cout << BLU"Before swapping:" RES;
		std::cout << "  c1: " << c1 << ", c2: " << c2 << "\n";
		
		::swap(c1, c2);
		std::cout << "         c1: " << c1 << ", c2: " << c2 << "\n";
		
		std::cout << "Min: " << ::min(c1, c2) << "\n";
		std::cout << "Max: " << ::max(c1, c2) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two integers:\n" RES;
		int a = 33;
		int b = 77;
		
		std::cout << BLU"Before swapping:" RES;
		std::cout << "  a: " << a << ", b: " << b << "\n";

		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n\n";

		std::cout << "Min: " << ::min(a, b) << "\n";
		std::cout << "Max: " << ::max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two floats:\n" RES;
		float a = 3.3f;
		float b = 7.7f;
		
		std::cout << BLU"Before swapping:" RES;
		std::cout << "  a: " << a << ", b: " << b << "\n";

		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n\n";
		
		std::cout << "Min: " << ::min(a, b) << "\n";
		std::cout << "Max: " << ::max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two doubles:\n" RES;
		double a = 11.11;
		double b = 55.55;
		
		std::cout << BLU"Before swapping:" RES;
		std::cout << "         a: " << a << ", b: " << b << "\n";
		
		::swap(a, b);
		std::cout << "  a: " << a << ", b: " << b << "\n";
		
		// swap(a, b);
		// std::cout << "         a: " << a << ", b: " << b << "\n";
		// std::swap(a, b);
		// std::cout << "                  a: " << a << ", b: " << b << "\n\n";
		
		std::cout << "Min: " << ::min(a, b) << "\n";
		std::cout << "Max: " << ::max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two strings:\n" RES;
		std::string a = "wine";
		std::string b = "beer";

		std::cout << BLU"Before swapping:" RES;
		std::cout << "  a: " << a << ", b: " << b << "\n";
		
		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		
		// swap(a, b);
		// std::cout << "                  a: " << a << ", b: " << b << "\n";
		// std::swap(a, b);
		// std::cout << "                  a: " << a << ", b: " << b << "\n\n";
		
		std::cout << "Min: " << ::min(a, b) << "\n";
		std::cout << "Max: " << ::max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";

   
	// {
	// 	// TEST: IF IT CAN TAKE A CLASS (PROBABLY NOT MANDATORY)
	// 	//  IT SWAPS PUBLIC MEMBERS. PRIVATE MEMBERS I DID NOT TRY

	// 	Whatever A, B;
	// 	A.x = 44;
	// 	B.x = 99;
	// 	A.s = "abcd";
	// 	B.s = "efgh";

	// 	std::cout << BLU"\nSwap public members in two objects:\n" RES;
	// 	std::cout << BLU"Before swapping:" RES;
	// 	std::cout << "  A.x: " << A.x << ",   B.x: " << B.x << "\n";
	// 	std::cout << "                  A.s: " << A.s << ", B.s: " << B.s << "\n";

	// 	std::cout << BLU"\nswap()\n" RES;
	// 	swap(A, B);
	// 	std::cout << "        A.x: " << A.x << ",   B.x: " << B.x << "\n";
	// 	std::cout << "                 A.s: " << A.s << ", B.s: " << B.s << "\n";
		
		
	// 	std::cout << BLU"\n::swap()\n" RES;
	// 	::swap(A, B);
	// 	std::cout << "        A.x: " << A.x << ",   B.x: " << B.x << "\n";
	// 	std::cout << "                 A.s: " << A.s << ", B.s: " << B.s << "\n";
		
	// 	std::cout << BLU"\nstd::swap()\n" RES;
	// 	std::swap(A, B);
	// 	std::cout << "                A.x: " << A.x << ",   B.x: " << B.x << "\n";
	// 	std::cout << "                A.s: " << A.s << ", B.s: " << B.s << "\n";

	// 	std::cout << BLU"\nMin() and Max() \n" RES;
	// 	std::cout << "   Min x: " <<      min(A.x, B.x) << "\n";
	// 	std::cout << "   Min x: " <<    ::min(A.x, B.x) << "\n";
	// 	std::cout << "   Min x: " << std::min(A.x, B.x) << "\n\n";

	// 	std::cout << "   Max x: " <<      max(A.x, B.x) << "\n";
	// 	std::cout << "   Max x: " <<    ::max(A.x, B.x) << "\n";
	// 	std::cout << "   Max x: " << std::max(A.x, B.x) << "\n\n";

	// 	std::cout << "   Min s: " <<      min(A.s, B.s) << "\n";
	// 	std::cout << "   Min s: " <<    ::min(A.s, B.s) << "\n";
	// 	std::cout << "   Min s: " << std::min(A.s, B.s) << "\n\n";
		
	// 	std::cout << "   Max s: " <<      max(A.s, B.s) << "\n";
	// 	std::cout << "   Max s: " <<    ::max(A.s, B.s) << "\n";
	// 	std::cout << "   Max s: " << std::max(A.s, B.s) << "\n\n";
	// }
	
	return 0;
}