/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 14:40:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/28 14:13:24 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "colors.h"


// typename T::iterator it = std::find(arr.begin(), arr.end(), n); // FIND IS C11 ???


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

	for (unsigned long i = 0; i < arr.size(); i++)
	{
		//std::cout << "   i" << i << ",  loop " << *it << "\n";
		if (n == *it)
			return (it);
		it++;
	}
	std::cout << LRD"Element not found\n" RES;
	throw (std::exception());
	// it = arr.end();
	// return (it);
}

#endif
