/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:29 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/15 15:35:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


Animal::Animal()
{
	_type = "animal";
	test = 33;
	std::cout << GRE"Default constructor Animal, type " << RES << _type << "\n";
}

// Animal::Animal(std::string &type)
// {
// 	std::cout << GRE"String Constructor called, Animal, type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
Animal::Animal(const Animal &animal)
{
	std::cout << GRE"Copy constructor Animal, type" << _type << "\n" << RES;
	*this = animal;
}


// Destructor
Animal::~Animal()
{
	std::cout << GRE"Destructor Animal, type " << RES << _type << "\n";

}

// Overload operators
Animal &Animal::operator= (const Animal &animal)
{
	std::cout << GRE"Overload assignment operator Animal\n" << RES;
	if (this == &animal)
		return (*this);
	this->_type = animal._type;
	return (*this);
} 

// Public member functions
/*
If an object is declared as: Animal *cat = new Animal()
Then his each member method must be const inside this class.
So compiler can guarantee that calling cat.method() will not change 
the cat.
*/
// IT IS VIRTUAL SPECIFIER IN THE CLASS
// void Animal::makeSound(void) 
void Animal::makeSound(void) const
{
	std::cout << BLU"Animal makeSound(): no sound\n" << RES;
}

// Getter
void Animal::getType()
{
	std::cout << "Animal getType: type " << _type << "\n";
}






// SOME TESTES ///////////////////////////////////////////////
void Animal::printTest(void) const
{
	std::cout << "Test, printed from Animal : " << test << "\n";
}

void Animal::printTest_no_const(void) const
{
	std::cout << "Test 2 NO CONST, printed from Animal : " << test << "\n";
}

void Animal::justInAnimal(void) const
{
	std::cout << "This function is just in base class Animal\n";	
}