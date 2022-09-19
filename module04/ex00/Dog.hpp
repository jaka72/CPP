#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"

class Dog: public Animal
{
	private:
		std::string	_type;

	public:
	
		// Constructors
		Dog();
		//Cat(std::string &type); // not sure to leave the &
		Dog(const Dog &dog);

		// Destructor
		~Dog();

		// Overload operators
		Dog &operator= (const Dog &dog);

		// Public member functions
		void makeSound(void) const;

};

#endif
