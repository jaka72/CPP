/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 12:48:19 by jmurovec      ########   odam.nl         */
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
		virtual ~Animal();

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
