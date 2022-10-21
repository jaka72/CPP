/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 16:28:28 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <stdio.h>		// for perror
#include <stdlib.h>		// fo exit

// #include "Cat.hpp"	// ??? THIS HEADER CANNOT BE HERE, BUT IN MAIN.C ??? (error, cannot convert Cat* to const Animal*) 
// #include "Dog.hpp"
#include "colors.h"

class Animal : public Brain
{
	protected:
		std::string	_type;

	public:

		// Constructors
		Animal();

		//Animal(std::string &type); // not sure to leave the &

		// Copy constructor
		Animal(const Animal &animal);

		// Parameterized constr.
		Animal(std::string type);


		// Destructor
		//  ~Animal();
		virtual ~Animal();	// MUST BE virtual destr, because Class Animal is polimorfic.

		// Overload operators
		Animal &operator= (const Animal &animal);

		// Public member functions
		//       void makeSound(void) const;		// IT MUST HAVE const, WHEN DECLARED AS
		 virtual void makeSound(void) const;		// IT MUST HAVE const, WHEN DECLARED AS
													//		Animal *a = new Animal();  ???

		// Getter
		virtual std::string getType() const;
		
		// Setter
		virtual void setType(std::string type);


		// To work with Brain ////////////////////////////////////////////////////////////
		// In case: Animal *cat1 = new Cat()		Whithout this not possible to call cat1->setIdea()
		virtual void getIdea(int n) const;
		virtual void setIdea(int n, std::string idea);


		// SOME TESTS ////////////////////////
		//virtual void printTest() const;
		//virtual void printTest_no_const() const;

		// Test to see if it's visible in Cat=Cat
		//void justInAnimal() const;
};

#endif