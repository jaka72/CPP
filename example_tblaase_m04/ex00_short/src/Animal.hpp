/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:24:26 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/17 10:15:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class Animal
{
	protected:
		std::string _type;

	public:
	// Constructors
		Animal();
	// 	Animal(const Animal &copy);

	// // Deconstructors
	// 	virtual ~Animal();

	// // Overloaded Operators
	// 	Animal &operator=(const Animal &src);

	// // Public Methods
	// 	virtual void makeSound(void)const;
	// // Getter
	// 	std::string getType(void)const;
	// // Setter

};

