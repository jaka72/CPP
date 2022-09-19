#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string _type;

	public:

		// Constructors
		Cat();
		// //Cat(std::string &type); // not sure to leave the &
		// Cat(const Cat &cat);

		// // Destructor
		// ~Cat();

		// // Overload operators
		// Cat &operator= (const Cat &cat);

		// // Public member functions
		// void makeSound(void);

};

#endif