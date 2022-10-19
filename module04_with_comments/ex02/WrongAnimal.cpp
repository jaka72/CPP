/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:58:31 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/19 20:04:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal()
{
	_type = "default";
	test = 33;
	std::cout << GRE"Default Constructor: WrongAnimal, type " << RES << _type << "\n";
}

// Param. constr.
WrongAnimal::WrongAnimal(std::string &type)
{
	std::cout << GRE"String Constructor, WrongAnimal, type" << RES << type << "\n" << RES;
	// _type = type;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << GRE"Copy Constructor, WrongAnimal, type" << RES << _type << "\n" << RES;
	*this = animal;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << GRE"Destructor WrongAnimal, type " << RES << _type << "\n" << RES;

}

// Overload operators
WrongAnimal &WrongAnimal::operator= (const WrongAnimal &wranimal)
{
	std::cout << GRE"Assignation operator for WrongAnimal\n" << RES;
	if (this == &wranimal)
		return (*this);
	this->_type = wranimal._type;
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
void WrongAnimal::makeSound(void) const
{
	std::cout << BLU"Called makeSound() for class Animal (no sound)\n" << RES;
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
