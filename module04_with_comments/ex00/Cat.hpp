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

		// Copy constructor
		//Cat(std::string &type); // not sure to leave the &
		Cat(const Cat &cat);

		// Destructor
		virtual ~Cat();

		// Overload operators
		Cat &operator= (const Cat &cat);

		// Public member functions
		// void makeSound(void);
		void makeSound(void) const;

		// Getter
		void getType();


		// SOME TESTS //////////////////////////////////

		// void printTest(void);
		void printTest(void) const;

		// void printTest_no_const(void);
		void printTest_no_const(void) const;


};

#endif
