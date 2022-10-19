/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:58:51 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/19 14:58:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << GRE"Default Constructor:              type " << RES << _type << "\n";
}

// Cat::Cat(std::string &type)
// {
// 	std::cout << GRE"Constructor for type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
WrongCat::WrongCat(const WrongCat &wrcat) : WrongAnimal(wrcat)
{
	std::cout << GRE"Copy Constructor:         type" << RES << _type << "\n" << RES;
	*this = wrcat;
}
// Destructor
WrongCat::~WrongCat()
{
	std::cout << GRE"Destructor: WrongCat\n" << RES;

}

// Overload operators
WrongCat &WrongCat::operator= (const WrongCat &wrcat)
{
	std::cout << GRE"Assignation operator for Cat\n" << RES;
	if (this == &wrcat)
		return (*this);
	this->_type = wrcat._type;
	return (*this);
} 



// Public member functions
void WrongCat::makeSound(void) const
{
	std::cout << BLU << _type << " says: 'Wrong Miaaw!'\n" << RES;
}

