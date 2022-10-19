/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 19:27:39 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << GRE"   Default Constructor Cat, type: " << RES << _type << "\n";
}


// Parameterized constr.
Cat::Cat(std::string type)  : Animal()  // ??? DOES IT NEED :Animal HERE?
{										// maybe not, if you don't want to change any values	
	std::cout << GRE"Param. constructor, Cat, type: " << RES << type << "\n" << RES;
	this->_type = type;
}


// Copy constructor
Cat::Cat(const Cat &cat) : Animal()
{
	std::cout << GRE"   Copy Constructor Cat, type: " << RES << _type << "\n" << RES;
	*this = cat;
}


// Destructor
Cat::~Cat()
{
	std::cout << GRE"   Destructor Cat, type "<< RES<< _type << "\n" << RES;

}

// Overload operators
Cat &Cat::operator= (const Cat &cat)
{
	std::cout << GRE"   Assignation operator Cat\n" << RES;
	if (this == &cat)
		return (*this);
	this->_type = cat._type;
	return (*this);
} 


// Public member functions
void Cat::makeSound(void) const
{
	std::cout << BLU"   Cat (type " << _type << ") makeSound: 'Miauw!'\n" << RES;
}


// Getter
std::string Cat::getType() const
{
	std::cout << BLU"   Cat getType: " << _type << "\n" << RES;
	return this->_type;
}

// Setter
void Cat::setType(std::string type)
{
	this->_type = type;
}
