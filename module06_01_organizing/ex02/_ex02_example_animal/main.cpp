/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 20:53:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/05 13:44:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>	// for itoa (std::stringstream out;)

#include "Dog.hpp"
#include "Cat.hpp"

#include "colors.h"


// void	check_allocation(const Animal *anm)
// {
// 	if (anm == NULL)
// 	{
// 		perror("Animal allocation failed. \n Exit\n");
// 		exit (1);
// 	}
// }



int main()
{
	{	
		std::cout << "- - - Try creating object of abstract class - - - - - - -\n";
		// Animal  anm1;						// not possible
		// Animal *anm2 = new Animal();			// not possible
		// const Animal* j = new Animal();		// not possible
	}
	 	std::cout << "\n- - - - - - - - - - - -  - - - - - - - - - - - - - - - -\n\n\n";
	{	
		std::cout << "- - - Create derived object from abstract class - - - - -\n";
		const Animal* cat1 = new Cat();
		delete cat1;

		const Animal* dog1 = new Dog();
		delete dog1;
	}

		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return (0);
}
