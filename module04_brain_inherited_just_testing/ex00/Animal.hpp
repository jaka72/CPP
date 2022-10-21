/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 10:24:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include "colors.h"

class Animal
{
	protected:
		std::string	_type;

	public:
	
		// Constructors
		Animal();

		// Parameterized constr.
		Animal(std::string type);

		// Copy constructor
		Animal(const Animal &animal);


		// Destructor
		virtual ~Animal();	// MUST BE virtual destr, because Class Animal is polimorfic

		// Overload operators
		Animal &operator= (const Animal &animal);

		// Public member functions
		 virtual void makeSound(void) const;

		// Getter
		virtual std::string getType() const;
		
		// Setter
		virtual void setType(std::string type);
};

#endif
