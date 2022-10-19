/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:30:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 15:01:43 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


// Constructor
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
	// std::cout << GRE"Destructor WrongAnimal, type" << _type << "\n" << RES;
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
	/*
	If an object is declared as: Animal *cat = new Animal()
	Then his each member method must be const inside this class.
	So compiler can guarantee that calling cat.method() will not change 
	the cat.
	*/
// IT IS VIRTUAL SPECIFIER IN THE CLASS
void WrongAnimal::makeSound(void) const
{
	std::cout << BLU << "WrongAnimal (type " << _type << ") makeSound: 'wrong sound'\n" << RES;
}


// Getter
void WrongAnimal::getType() const
{
	// std::cout << "From WrongAnimal: type " << _type << "\n";
	std::cout << BLU"Animal getType: " << _type << RES"\n";

}


// Setter
void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}
