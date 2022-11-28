/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_int_iterator.cpp                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 12:09:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/26 13:45:43 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm> // std::find()



std::vector <int> ::iterator easyfind(std::vector<int>arr, const int n)
{
	// typename   T   ::iterator it = std::find(arr.begin(), arr.end(), n);
	std::vector <int> ::iterator it = std::find(arr.begin(), arr.end(), n);

	if (it == arr.end())
	 	throw (std::exception());
	std::cout << "\nit found: " << *it << "\n";

	return (it);

}

#define SIZE 5

int main()
{
	std::vector<int> arr;
	//int arr[10];

	for (int i = 0; i < SIZE; i++)
		arr.push_back((i+1) * 10);

	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";


	// int std::iterator it1 = arr.begin();
	std::cout << "size: " << arr.size() << "\n";
	



	try
	{
		std::vector<int>::iterator it = ::easyfind(arr, 30);
		std::cout << "After easyfind: " << *it << "\n"; // DOES NOT PRINT THE FOUND ELEMENT,
	}													// BUT SOME RANDOM GARBAGE
	catch(const std::exception& e)
	{
		std::cerr << "\nElement not found (" << e.what() << ")\n";
	}
	std::cout << "\n";
}