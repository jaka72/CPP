/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:30:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/15 15:30:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


// Constructor
WrongAnimal::WrongAnimal()
{
	_type = "wronganimal";
	test = 33;
	std::cout << GRE"Default onstructor WrongAnimal, type " << RES << _type << "\n";
}


// Parameterized constructor
WrongAnimal::WrongAnimal(std::string &type)
{
	std::cout << GRE"String Constructor WrongAnimal, type" << type << "\n" << RES;
	// _type = type;
}


// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &animal)
{
	std::cout << GRE"Copy Constructor WrongAnimal, type" << _type << "\n" << RES;
	*this = animal;
}


// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << GRE"Destructor WrongAnimal, type" << _type << "\n" << RES;

}


// Overload operators
WrongAnimal &WrongAnimal::operator= (const WrongAnimal &wranimal)
{
	std::cout << GRE"Overload assignment operator WrongAnimal\n" << RES;
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
	std::cout << BLU"WrongAnimal makeSound():  no sound\n" << RES;
}


// Getter
void WrongAnimal::getType()
{
	std::cout << "From WrongAnimal: type " << _type << "\n";
}




// ///////////////////////////////////////////////////////
void WrongAnimal::printTest(void)
{
	std::cout << "Test from Animal : " << test << "\n";
}

