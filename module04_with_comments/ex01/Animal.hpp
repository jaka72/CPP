#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

// #include "Cat.hpp"
// #include "Dog.hpp"
#include "colors.h"

class Animal
{
	protected:
		std::string	_type;
		//int test;

	public:
	
		// Constructors
		Animal();
		//Animal(std::string &type); // not sure to leave the &
		Animal(const Animal &animal);

		// Destructor
		virtual ~Animal();
		// ~Animal();

		// Overload operators
		Animal &operator= (const Animal &animal);

		// Public member functions
		virtual void makeSound(void) const;		// IT MUST HAVE const, WHEN DECLARED AS
										//		Animal *a = new Animal(); 
		//void printTest(void);

		/////// NOT SURE IF IT MUST BE HERE, BECAUSE IN THE EXAMPLE ITS NOT
		// // Setter
		// void setIdea(int n, std::string idea);

		// // Getter
		// void getIdea(int n);



};

#endif
