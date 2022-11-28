/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 12:09:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/27 21:03:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "easyfind.hpp"
#include <vector>
#include <algorithm>
// #include <array>  // only c11


// template <typename T>
// typename T::iterator easyfind(T arr, const int n)
// {
// 	typename T::iterator it = std::find(arr.begin(), arr.end(), n);
	
// 	if (it == arr.end())
// 	 	throw (std::exception());
	
// 	std::cout << "\nFound it element: " << *it << "\n";
		
// 	// std::cout << "\narr[i]:   " << arr[7] << "\n";
// 	// std::cout << "n:   " << n << "\n";
// 	// typename T::iterator it1 = arr.begin();
// 	// std::cout << "it1: " << *it1 << "\n";
// 	// typename T::iterator it2 = arr.end();
// 	// std::cout << "it2: " << *it2 << "\n";
// 	return (it);
// }

template <typename T>
void	printElements(T arr)
{
	std::cout << "Print all elements:\n";
	for (typename T::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}


#define SIZE 5

int main()
{

	//long unsigned int len = 5;
	long unsigned int i;
	std::vector<int> arr;

	for (i = 0; i < SIZE; i++)
		arr.push_back((i+1) * 10);

	printElements(arr);

	try
	{
		std::vector<int>::iterator it = ::easyfind(arr, 30);
		std::cout << "after easyfind: " << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nIndex out of range (" << e.what() << ")\n";
	}

	try
	{
		std::vector<int>::iterator it = ::easyfind(arr, 999);
		std::cout << "after easyfind: " << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "\nIndex out of range (" << e.what() << ")\n";
	}

	std::cout << "\n";
}