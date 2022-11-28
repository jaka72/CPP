/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple_array.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 12:09:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/26 13:46:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
// #include <iomanip>
#include <vector>
// #include <list>


template <typename T>
T easyfind(T *arr, const T n)
// T easyfind(T arr, const int n)
// typename T::iterator easyfind(T arr, const int n)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == n)
			return (arr[i]);
	}
	return (arr[0]);

	// typename T::iterator it = std::find(arr.begin(), arr.end(), n);
	// if (it == arr.end())
	// 	return (-1);
	// return (it);

}



int main()
{
	// std::vector<int> arr;
	int arr[10];

	for (int i = 0; i < 10; i++)
		arr[i] = i*10;
		// arr.push_back(33);

	arr[3] = 999;

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << " ";

	easyfind<int>(arr, 999);
	// std::vector<int>::iterator it = ::easyfind(arr, 999);

	// std::cout << *it << "\n";


	std::cout << "\n";
}