#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

// #include "Cat.hpp"
// #include "Dog.hpp"
// #include "Animal.hpp"
#include "colors.h"

class Animal
{
	protected:
		std::string	_type;
		int test;

	public:
	
		// Constructors
		Animal();
		// Animal(std::string &type); // not sure to leave the &
		// Animal(const Animal &animal);

		// // Destructor
		// ~Animal();

		// // Overload operators
		// Animal &operator= (const Animal &animal);

		// // Public member functions
		// void makeSound(void);
		// void printTest(void);

};




#endif

