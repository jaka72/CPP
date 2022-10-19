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

		// Param. constr.
		Cat(std::string type);


		// Copy constructor
		Cat(const Cat &cat);

		// Destructor
		virtual ~Cat();

		// Overload operators
		Cat &operator= (const Cat &cat);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;

		// Setter
		void setType(std::string type);
};

#endif
