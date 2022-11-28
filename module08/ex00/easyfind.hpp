/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 14:40:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/26 16:49:18 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
 #define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
typename T::iterator easyfind(T arr, const int n)
{
	typename T::iterator it = std::find(arr.begin(), arr.end(), n);
	
	if (it == arr.end())
	 	throw (std::exception());
	
	std::cout << "\nFound *it element: " << *it << "\n";
		
	// std::cout << "\narr[i]:   " << arr[7] << "\n";
	// std::cout << "n:   " << n << "\n";
	// typename T::iterator it1 = arr.begin();
	// std::cout << "it1: " << *it1 << "\n";
	// typename T::iterator it2 = arr.end();
	// std::cout << "it2: " << *it2 << "\n";
	return (it);
}


 #endif