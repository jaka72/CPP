/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:27:30 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 19:29:01 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GRE"   Default constructor Dog, type: " << RES << _type << "\n";

}


// Parameterized constr.
Dog::Dog(std::string type) : Animal()
{
	std::cout << GRE"Param. constructor, Dog, type: " << RES << type << "\n" << RES;
	this->_type = type;
}


// Copy constructor
Dog::Dog(const Dog &dog) : Animal()
{
	std::cout << GRE"   Copy constructor Dog, type: " << RES << _type << "\n";
	*this = dog;
}


// Destructor
Dog::~Dog()
{
	std::cout << GRE"   Destructor Dog, type " << RES << _type << "\n";

}

// Overload operators
Dog &Dog::operator= (const Dog &dog)
{
	std::cout << GRE"   Overload assignment operator Dog\n" << RES;
	if (this == &dog)
		return (*this);

	this->_type = dog._type;
	return (*this);
} 

// Getter
std::string Dog::getType() const
{
	std::cout << BLU"   Cat getType: " << _type << "\n" << RES;
	return this->_type;
}

// Setter
void Dog::setType(std::string type)
{
	this->_type = type;
}


// Public member functions
void Dog::makeSound(void) const
{
	std::cout << BLU << "   Dog (type " << _type << ") makeSound: 'Wooof!'\n" << RES;
}
