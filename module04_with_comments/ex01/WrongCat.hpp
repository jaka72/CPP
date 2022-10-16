#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		std::string _type;

	public:

		// Constructors
		WrongCat();
		//Cat(std::string &type); // not sure to leave the &
		WrongCat(const WrongCat &wrcat);

		// Destructor
		~WrongCat();

		// Overload operators
		WrongCat &operator= (const WrongCat &wrcat);

		// Public member functions
		void makeSound(void) const;
};

#endif
