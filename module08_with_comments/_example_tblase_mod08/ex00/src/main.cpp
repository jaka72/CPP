/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:36:20 by tblaase       #+#    #+#                 */
/*   Updated: 2022/11/28 13:20:05 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <list>

int main()
{
	std::list<int> test;
	test.push_back(155);
	test.push_back(156);
	test.push_back(157);

	std::list<int>::const_iterator	it = test.end();

	try
	{
		it = ::easyfind(test, 155);
		std::cout << "tblase it: " << *it << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	it = test.end();

	try
	{
		it = ::easyfind(test, 15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	return (0);
}
