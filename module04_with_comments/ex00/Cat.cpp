/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:24:23 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/15 15:35:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << GRE"   Default Constructor Cat, type " << RES << _type << "\n";
}

// Cat::Cat(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }


// Copy constructor
Cat::Cat(const Cat &cat) : Animal()
{
	std::cout << GRE"   Copy Constructor Cat, type " << _type << "\n" << RES;
	*this = cat;
}


// Destructor
Cat::~Cat()
{
	std::cout << GRE"   Destructor called Cat, type " << _type << "\n" << RES;

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
// void Cat::makeSound(void)
{
	std::cout << BLU << "   Cat " << _type << " says: 'Miauw!'\n" << RES;
}


// Getter
void Cat::getType()
{
	std::cout << "   Cat getType: type " << _type << "\n";
}







// SOME TESTS ////////////////////////////////////////////////////
void Cat::printTest(void) const
// void Cat::printTest(void)
{
	std::cout << "   Test, printed from Cat : " << test << "\n";
}

void Cat::printTest_no_const(void) const
// void Cat::printTest_no_const(void)
{
	std::cout << "   Test 2 NO CONST, printed from Cat : " << test << "\n";
}