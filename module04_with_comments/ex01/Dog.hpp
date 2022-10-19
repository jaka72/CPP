#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"

class Dog: public Animal
{
	private:
//		std::string		_type; 		// MAYBE NOT NEEDED, ITS INHERITED FROM Animal
		Brain			*_brain;	//  A POINTER TO OBJECT


	public:
	
		// Constructors
		Dog();

		// Param. constr.
		Dog(std::string type);

		// Copy constructor
		Dog(const Dog &dog);

		// Destructor
		~Dog();

		// Overload operators
		Dog &operator= (const Dog &dog);

		// Public member functions
		void makeSound(void) const;


		// Setter
		void setIdea(int n, std::string idea) const;

		void setType(std::string type);


		// Getters
		void getIdea(int n) const;

		std::string getType() const;

};

#endif
