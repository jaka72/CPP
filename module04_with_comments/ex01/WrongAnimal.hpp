#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

// #include "Cat.hpp"
// #include "Dog.hpp"
#include "colors.h"

class WrongAnimal
{
	protected:
		std::string	_type;
		int test;

	public:
	
		// Constructors
		WrongAnimal();
		WrongAnimal(std::string &type); // not sure to leave the &
		WrongAnimal(const WrongAnimal &wranimal);

		// Destructor
		virtual ~WrongAnimal();

		// Overload operators
		WrongAnimal &operator= (const WrongAnimal &wranimal);

		// Public member functions
		virtual void makeSound(void) const;		// IT MUST HAVE const, WHEN DECLARED AS
										//		Animal *a = new Animal(); 
		void printTest(void);

};

#endif
