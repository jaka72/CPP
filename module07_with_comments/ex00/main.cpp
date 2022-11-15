/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/13 10:55:17 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

/*
	THE FUNCTION swap() IS ALREADY INCLUDED SOMEWHERE IN std::
	OR IN iostream ????, IT WORKS WITH ALL DATA TYPES,
	BUT IF YOU OVERRIDE IT WITH A TEMPLATE swap()
	IT WILL NOT USE THE TEMPLATE, WHEN YOU GIVE IT STRINGS      INTS            STRINGS
	swap() works in 3 variants for ints:         swap()         mine              std
											   ::swap()         mine              mine
											std::swap()         std               std
	
															   INTS            STRINGS
												 min()         mine              mine
											   ::min()         mine              mine
											std::min()         std               std
	CHECK ON MAC !!!

	THIS CAN BE SOLVED WITH DOUBLE COLON PREPENDED TO THE FUNCTION NAME:   ::swap()
		operator:: 	Is called 'global scope resolution operator'
					It resolves to the top-level configuration (most outer class/namespace ???)

	I also added a class, to see if T can also be a class. But I guess it is not mandatory.
*/


int main()
{
	{
		std::cout << BLU"\nSwap two chars:\n" RES;
		std::cout << BLU"Before swapping:" RES;

		char a = 'x', b = 'y';
		std::cout << "  a: " << a << ", b: " << b << "\n";
		swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		
		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		
		std::swap(a, b);
		std::cout << "                  a: " << a << ", b: " << b << "\n\n";
		
		std::cout << "Min: " << min(a, b) << "\n";
		std::cout << "Max: " << max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two integers:\n" RES;
		std::cout << BLU"Before swapping:" RES;
		
		int a = 3, b = 7;
		std::cout << "  a: " << a << ", b: " << b << "\n";
		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n\n";

		std::cout << "Min: " << min(a, b) << "\n";
		std::cout << "Max: " << max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two floats:\n" RES;
		std::cout << BLU"Before swapping:" RES;
		
		float a = 3.3f, b = 7.7f;
		std::cout << "  a: " << a << ", b: " << b << "\n";
		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n\n";
		std::cout << "Min: " << min(a, b) << "\n";
		std::cout << "Max: " << max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two doubles:\n" RES;
		std::cout << BLU"Before swapping:" RES;
		
		double a = 11.11, b = 55.55;
		std::cout << "  a: " << a << ", b: " << b << "\n";
		     swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		   ::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		std::swap(a, b);
		std::cout << "                  a: " << a << ", b: " << b << "\n\n";
		
		// std::cout << " a: " << a << ", b: " << b << "\n";
		std::cout << "Min: " << min(a, b) << "\n";
		std::cout << "Max: " << max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	{
		std::cout << BLU"\nSwap two strings:\n" RES;
		std::cout << BLU"Before swapping:" RES;
		std::string a = "wine";
		std::string b = "beer";

		std::cout << "  a: " << a << ", b: " << b << "\n";
		swap(a, b);
		std::cout << "                  a: " << a << ", b: " << b << "\n";
		::swap(a, b);
		std::cout << "         a: " << a << ", b: " << b << "\n";
		std::swap(a, b);
		std::cout << "                  a: " << a << ", b: " << b << "\n\n";
		std::cout << "Min: " << min(a, b) << "\n";
		std::cout << "Max: " << max(a, b) << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n\n";

   
	{
		// TEST: IF IT CAN TAKE A CLASS (PROBABLY NOT MANDATORY)
		//  IT SWAPS PUBLIC MEMBERS. PRIVATE MEMBERS I DID NOT TRY

		Whatever A, B;
		A.x = 44;
		B.x = 99;
		A.s = "abcd";
		B.s = "efgh";

		std::cout << BLU"\nSwap public members in two objects:\n" RES;
		std::cout << BLU"Before swapping:" RES;
		std::cout << "  A.x: " << A.x << ",   B.x: " << B.x << "\n";
		std::cout << "                  A.s: " << A.s << ", B.s: " << B.s << "\n";

		std::cout << BLU"\nswap()\n" RES;
		swap(A, B);
		std::cout << "        A.x: " << A.x << ",   B.x: " << B.x << "\n";
		std::cout << "                 A.s: " << A.s << ", B.s: " << B.s << "\n";
		
		
		std::cout << BLU"\n::swap()\n" RES;
		::swap(A, B);
		std::cout << "        A.x: " << A.x << ",   B.x: " << B.x << "\n";
		std::cout << "                 A.s: " << A.s << ", B.s: " << B.s << "\n";
		
		std::cout << BLU"\nstd::swap()\n" RES;
		std::swap(A, B);
		std::cout << "                A.x: " << A.x << ",   B.x: " << B.x << "\n";
		std::cout << "                A.s: " << A.s << ", B.s: " << B.s << "\n";

		std::cout << BLU"\nMin() and Max() \n" RES;
		std::cout << "   Min x: " <<      min(A.x, B.x) << "\n";
		std::cout << "   Min x: " <<    ::min(A.x, B.x) << "\n";
		std::cout << "   Min x: " << std::min(A.x, B.x) << "\n\n";

		std::cout << "   Max x: " <<      max(A.x, B.x) << "\n";
		std::cout << "   Max x: " <<    ::max(A.x, B.x) << "\n";
		std::cout << "   Max x: " << std::max(A.x, B.x) << "\n\n";

		std::cout << "   Min s: " <<      min(A.s, B.s) << "\n";
		std::cout << "   Min s: " <<    ::min(A.s, B.s) << "\n";
		std::cout << "   Min s: " << std::min(A.s, B.s) << "\n\n";
		
		std::cout << "   Max s: " <<      max(A.s, B.s) << "\n";
		std::cout << "   Max s: " <<    ::max(A.s, B.s) << "\n";
		std::cout << "   Max s: " << std::max(A.s, B.s) << "\n\n";
	}
	
	return 0;
}