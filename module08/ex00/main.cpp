/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/26 12:09:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/28 14:15:19 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <algorithm>

// #include <array>  // only c11


template <typename T>
void	printElements(T arr)
{
	std::cout << "Print all elements:\n   ";
	for (typename T::iterator it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}


#define SIZE 0
#define TOFIND 55

int main()
{
	{
		std::cout << "Container Vector - - - - - - - - - - - - - - \n\n";
		long unsigned int i;
		std::vector<int> vect;

		for (i = 0; i < SIZE; i++)
			vect.push_back((i+1) * 10);

		printElements(vect);

		try
		{
			std::vector<int>::iterator it = ::easyfind(vect,  TOFIND);
			//if (it != vect.end())
			std::cout << GRN"Element found: " << *it << "\n" RES;
		}
		catch(const std::exception& e)
		{
			// std::cerr << "\nIndex out of range (" << e.what() << ")\n";
			std::cerr << "(" << e.what() << ")\n";
		}
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n\n";



	{
		std::cout << "\nContainer Decque - - - - - - - - - - - - - - - - \n\n";
		long unsigned int i;
		std::deque<int> arr;

		for (i = 0; i < SIZE; i++)
			arr.push_front((i+1) * 10);

		printElements(arr);

		try
		{
			std::deque<int>::iterator it = ::easyfind(arr,  TOFIND);
			//if (it != arr.end())
			std::cout << GRN"Element found: " << *it << "\n" RES;
		}
		catch(const std::exception& e)
		{
			// std::cerr << "\nIndex out of range (" << e.what() << ")\n";
			std::cerr << "(" << e.what() << ")\n";
		}
	}
	
	{
		std::cout << "\nContainer List - - - - - - - - - - - - - - - - \n\n";
		long unsigned int i;
		std::list<int> arr;

		for (i = 0; i < SIZE; i++)
			arr.push_back((i+1) * 10);

		printElements(arr);

		try
		{
			std::list<int>::iterator it = ::easyfind(arr,  TOFIND);
			//if (it != arr.end())
			std::cout << GRN"Element found: " << *it << "\n" RES;
		}
		catch(const std::exception& e)
		{
			// std::cerr << "\nIndex out of range (" << e.what() << ")\n";
			std::cerr << "(" << e.what() << ")\n";
		}
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n\n";



	{
		std::cout << "\nContainer Array (only C11)  - - - - - - - - - - - - - \n\n";
		std::array<int, 5> arr;		// ARRAY does not have push_back(), or push()

		arr.fill(22);
		printElements(arr);

		arr.fill(50);
		printElements(arr);

		//arr.fill( {10, 20, 30, 40, 50} );

		try
		{
			std::array<int, 5>::iterator it = ::easyfind(arr,  TOFIND);
			//if (it != arr.end())
			std::cout << GRN"Element found: " << *it << "\n" RES;
		}
		catch(const std::exception& e)
		{
			// std::cerr << "\nIndex out of range (" << e.what() << ")\n";
			std::cerr << "(" << e.what() << ")\n";
		}
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - \n\n\n";

}