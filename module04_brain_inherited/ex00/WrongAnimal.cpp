/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:30:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 10:28:18 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


// Default onstructor
WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << GRE"Default constructor WrongAnimal, type " << RES << _type << "\n";
}


// Parameterized constructor
WrongAnimal::WrongAnimal(std::string &type)
{
	std::cout << GRE"Param. constructor, WrongAnimal, type: " << RES << type << "\n" << RES;
}


// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << GRE"Copy Constructor WrongAnimal, type" << RES << _type << "\n" << RES;
	*this = animal;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << GRE"Destructor WrongAnimal, type " << RES << _type << "\n" << RES;
}


// Overload operators
WrongAnimal &WrongAnimal::operator= (const WrongAnimal &src)
{
	std::cout << GRE"Overload assignment operator WrongAnimal\n" << RES;
	if (this == &src)
		return (*this);
	this->_type = src._type;
	return (*this);
} 


// Public member functions
void WrongAnimal::makeSound(void) const
{
	std::cout << BLU << "WrongAnimal (type " << _type << ") makeSound: 'wrong sound'\n" << RES;
}


// Getter
std::string WrongAnimal::getType() const
{
	// std::cout << "From WrongAnimal: type " << _type << "\n";
	std::cout << BLU"WrongAnimal getType: " << _type << RES"\n";
	return this->_type;
}


// Setter
void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
