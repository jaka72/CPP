/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:27:30 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/16 21:21:11 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GRE"   Default constructor Dog, type " << RES << _type << "\n";

}

// Dog::Dog(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }


// Copy constructor
Dog::Dog(const Dog &dog) : Animal()
{
	std::cout << GRE"   Copy constructor Dog, type " << RES << _type << "\n";
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
void Dog::getType()
{
	std::cout << "   Dog getType(): type " << _type << "\n";
}



// Public member functions
void Dog::makeSound(void) const
{
	std::cout << BLU << "   Dog " << _type << " says: 'Wooof!'\n" << RES;
}



// SOME TESTS ////////////////////////////////////////////////////
