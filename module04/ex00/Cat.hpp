#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		std::string _type;

	public:

		// Constructors
		Cat();
		//Cat(std::string &type); // not sure to leave the &
		Cat(const Cat &cat);

		// Destructor
		virtual ~Cat();

		// Overload operators
		Cat &operator= (const Cat &cat);

		// Public member functions
		void makeSound(void) const;
};

#endif
