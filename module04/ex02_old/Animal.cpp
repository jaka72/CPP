/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:29 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 19:49:59 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal()
{
	_type = "Default";
	std::cout << GRE"Default constructor Animal, type: " << RES << _type << "\n";
}


// Parameterized constr.
Animal::Animal(std::string type)
{
	std::cout << GRE"Param. constructor, Animal, type: " << RES << type << "\n" << RES;
	this->_type = type;
}


// Copy constructor
Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << GRE"Copy constructor Animal, type: " << _type << "\n" << RES;
}


// Destructor
Animal::~Animal()
{
	std::cout << GRE"Destructor Animal, type " << RES << _type << "\n";
}


// Overload operators
Animal &Animal::operator= (const Animal &src)
{
	std::cout << GRE"Overload assignment operator Animal\n" << RES;
	if (this == &src)
		return (*this);
	this->_type = src._type;
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
	std::cout << BLU"Animal (type " << _type << ") makeSound: 'no sound!'\n" << RES;

}

// Getter
std::string Animal::getType() const
{
	std::cout << BLU"Animal getType: " << _type << RES"\n";
	return this->_type;
}

// Setter
void Animal::setType(std::string type)
{
	this->_type = type;
	std::cout << GRE"Setter: set type to '" << _type << "'\n" << RES;
}





// SOME TESTES ///////////////////////////////////////////////
// void Animal::printTest(void) const
// {
// 	std::cout << "Test, printed from Animal : " << test << "\n";
// }

// void Animal::printTest_no_const(void) const
// {
// 	std::cout << "Test 2 NO CONST, printed from Animal : " << test << "\n";
// }

// void Animal::justInAnimal(void) const
// {
// 	std::cout << "This function is just in base class Animal\n";	
// }