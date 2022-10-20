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
	
		// Constructor
		WrongAnimal();

		// Param. constr.
		WrongAnimal(std::string &type); // not sure to leave the &

		// Copy constructor
		WrongAnimal(const WrongAnimal &src);

		// Destructor
		virtual ~WrongAnimal();

		// Overload operators
		WrongAnimal &operator= (const WrongAnimal &src);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;

		// Setter
		virtual void setType(std::string type);
};

#endif
