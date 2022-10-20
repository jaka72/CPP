#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

#include "colors.h"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
	
		// Constructor
		WrongAnimal();


		// Parameterized constructor
		WrongAnimal(std::string &type);

		// Copy constructor
		WrongAnimal(const WrongAnimal &wranimal);

		// Destructor
		virtual ~WrongAnimal();

		// Overload operators
		WrongAnimal &operator= (const WrongAnimal &wranimal);

		// Public member functions
		void makeSound(void) const;
		
		// Getter
		std::string getType() const;

		// Setter
		virtual void setType(std::string type);
};

#endif
