/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/03 22:14:22 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "Data.hpp"


int main()
{
	Data *d1 = new Data();
	// Data *d1;
	uintptr_t i = reinterpret_cast<uintptr_t>(d1);
	std::cout << "d1: " << d1 << ",  i: " << i << "\n";

	d1 = NULL;
	std::cout << "d1: " << d1 << ",  i: " << i << "\n";

	d1 = reinterpret_cast<Data*>(i);

	std::cout << "d1: " << d1 << ",  i: " << i << "\n";
	
//	delete d1;


	//Data* d2;
	// uintptr_t i2 = (uintptr_t)d2;

	// *d2 = (void*)&d2;
	// uintptr_t i2 = (uintptr_t)(void*)&d2;
	// std::cout << "d2: " << d2 << ",  i2: " << i2 << "\n";

	// if (d2 == i2)
	// 	std::cout  << "yes\n";
	
	return 0;
}
