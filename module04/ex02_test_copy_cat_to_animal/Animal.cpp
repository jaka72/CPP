/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:29 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/22 20:58:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal()
{
	_type = "Default";
	std::cout << GRE"Default constructor Animal,  type " << RES << _type << "\n";
}


// Parameterized constr.
Animal::Animal(std::string &type)
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
	std::cout << GRE"Destructor Animal" << RES <<  "\n";
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



// //  Added to work with Brain in Cat and Dog
void Animal::setIdea(int n, std::string idea) 
{
	// just virtual, because Animal does not have Brain
	(void)n;
	(void)idea;
}

// Getters
void Animal::getIdea(int n) const
{
	// just virtual, because Animal does not have Brain
	(void)n;
}




// jaka testing
void Animal::test00()
{
	std::cout << "Test00, Printed from Animal\n";
}
