/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:35:36 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 19:41:13 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Default constructor
WrongCat::WrongCat() : WrongAnimal()
{
	_type = "wrongcat";
	std::cout << GRE"   Default constructor WrongCat, type " << RES << _type << "\n";
}

// Parameterized constr.
WrongCat::WrongCat(std::string type)  : WrongAnimal()
{
	std::cout << GRE"Param. constructor, Cat, type: " << RES << type << "\n" << RES;
	this->_type = type;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat &wrcat) : WrongAnimal()
{
	std::cout << GRE"   Copy Constructor WrongCat, type " << RES << _type << "\n" << RES;
	*this = wrcat;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << GRE"Destructor WrongCat, type " << RES << _type << "\n" << RES;
}

// Overload operators
WrongCat &WrongCat::operator= (const WrongCat &wrcat)
{
	std::cout << GRE"   Overload assignment operator WrongCat\n" << RES;
	if (this == &wrcat)
		return (*this);
	this->_type = wrcat._type;
	return (*this);
} 


// Public member functions
void WrongCat::makeSound(void) const
{
	std::cout << BLU << "   Wrongcat " << _type << " says: 'Wrong Miaaw!'\n" << RES;
}


// Setter
void WrongCat::setType(std::string type)
{
	this->_type = type;
}


// Getter
std::string WrongCat::getType() const
{
	std::cout << BLU"   From WrongCat: type " << _type << RES<< "\n";
	return this->_type;
}
