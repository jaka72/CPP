/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/24 16:51:17 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>      // std::setw
#include "iter.hpp"



int main()
{
	char		arrA[] = {'a', 'b', 'c', 'd', 'e'};
	int			arrB[] = {11, 22, 33, 44, 55};
	float		arrC[] = {11.1f, 22.2f, 33.3f, 44.4f, 55.5f};
	double		arrD[] = {11.1, 22.2, 33.3, 44.4, 55.5};
	std::string	arrE[] = {"John", "Maria", "Joseph", "Natasha", "George"};

	
	size_t lenA = sizeof(arrA) / sizeof(arrA[0]);
	size_t lenB = sizeof(arrB) / sizeof(arrB[0]);
	size_t lenC = sizeof(arrC) / sizeof(arrC[0]);
	size_t lenD = sizeof(arrD) / sizeof(arrD[0]);
	size_t lenE = sizeof(arrE) / sizeof(arrE[0]);
	
	
	{
		::iter(arrA, lenA, print_elem);
		::iter(arrB, lenB, print_elem);
		::iter(arrC, lenC, print_elem);
		::iter(arrD, lenD, print_elem);
		::iter(arrE, lenE, print_elem);
		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
	}
	return 0;
}






// int main()
// {
// 	char		arrA[] = {'a', 'b', 'c', 'd', 'e'};
// 	int			arrB[] = {11, 22, 33, 44, 55};
// 	float		arrC[] = {11.1f, 22.2f, 33.3f, 44.4f, 55.5f};
// 	double		arrD[] = {11.1, 22.2, 33.3, 44.4, 55.5};
// 	std::string	arrE[] = {"John", "Maria", "Joseph", "Natasha", "George"};

	
// 	size_t lenA = sizeof(arrA) / sizeof(arrA[0]);
// 	size_t lenB = sizeof(arrB) / sizeof(arrB[0]);
// 	size_t lenC = sizeof(arrC) / sizeof(arrC[0]);
// 	size_t lenD = sizeof(arrD) / sizeof(arrD[0]);
// 	size_t lenE = sizeof(arrE) / sizeof(arrE[0]);
	
	
// 	{
// 		::iter(arrA, lenA, print_elem);
// 		::iter(arrB, lenB, print_elem);
// 		::iter(arrC, lenC, print_elem);
// 		::iter(arrD, lenD, print_elem);
// 		::iter(arrE, lenE, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
// 	}

// 	{
// 		::iter(arrA, lenA, print_elem);
// 		::iter(arrA, lenA, addOne);
// 		::iter(arrA, lenA, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
		

// 		::iter(arrB, lenB, print_elem);
// 		::iter(arrB, lenB, addOne);
// 		::iter(arrB, lenB, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";


// 		::iter(arrC, lenC, print_elem);
// 		::iter(arrC, lenC, addOne);
// 		::iter(arrC, lenC, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";


// 		::iter(arrD, lenD, print_elem);
// 		::iter(arrD, lenD, addOne);
// 		::iter(arrD, lenD, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";


// 		::iter(arrE, lenE, print_elem);
// 		::iter(arrE, lenE, addOne);
// 		::iter(arrE, lenE, print_elem);
// 		std::cout << "\n\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n";
// 	}

// 	return 0;
// }
