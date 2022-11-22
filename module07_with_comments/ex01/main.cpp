/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/22 19:58:42 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>      // std::setw
#include "iter.hpp"
 
template <typename T>

void    print_arr(T &c)
{
	std::cout << std::setw(10) << std::left;
	std::cout  << c;;
}


// template <typename T>

// void change(T &c)
// {
// 	 c = c - 32;
// 	//c = std::toupper(static_cast<unsigned char>(c));
// }


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
		::iter(arrA, lenA, print_arr);
		::iter(arrB, lenB, print_arr);
		::iter(arrC, lenC, print_arr);
		::iter(arrD, lenD, print_arr);
		::iter(arrE, lenE, print_arr);
	}
	
	return 0;
}
