/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 13:25:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H


#include <sstream>		// to convert i to a
#include <iostream>
#include <string>
#include <stdio.h>		// for perror
#include <stdlib.h>		// fo exit


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


		// To work with Brain ////////////////////////////////////////////////////////////
		// In case: Animal *cat1 = new Cat()	Without this is not possible to call cat1->setIdea()
		virtual void getIdea(int n) const;
		virtual void setIdea(int n, std::string idea);

};

#endif
