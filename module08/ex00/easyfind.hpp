/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 14:40:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/30 10:58:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

//#include <algorithm>	// not needed
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include "colors.h"



template <typename T>
typename T::iterator easyfind(T& arr, const int n)
{
	std::cout << "Start easyfind()\n";

	typename T::iterator it = arr.begin();
	if (it == arr.end())
	{
		std::cout << LRD"Array is empty.\n" RES;
		throw (std::exception());
	}

	typename T::iterator result;
	result = find(arr.begin(), arr.end(), n);
	
	if (*result == n)
		return (result);
		
	throw (std::out_of_range(LRD "c Element not found" RES));
	// throw (std::runtime_error(LRD "c Element not found" RES));


	// OLD WAY
	// for (unsigned long i = 0; i < arr.size(); i++)
	// {
	// 	//std::cout << "   i" << i << ",  loop " << *it << "\n";
	// 	if (n == *it)
	// 		return (it);
	// 	it++;
	// }
	// std::cout << LRD"Element not found\n" RES;
	// throw (std::exception());
}

#endif
