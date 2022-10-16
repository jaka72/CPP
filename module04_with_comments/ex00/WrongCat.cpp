/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:35:36 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/15 15:33:12 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "wrongcat";
	std::cout << GRE"   Default constructor WrongCat, type " << RES << _type << "\n";

}

// Cat::Cat(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
WrongCat::WrongCat(const WrongCat &wrcat) : WrongAnimal()
{
	std::cout << GRE"   Copy Constructor WrongCat, type " << _type << "\n" << RES;
	*this = wrcat;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << GRE"   Destructor  WrongCat, type " << _type << "\n" << RES;

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


// Getter
void WrongCat::getType()
{
	std::cout << "   From WrongCat: type " << _type << "\n";
}
