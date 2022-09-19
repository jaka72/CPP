#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << GRE"Default Constructor called:         type " << RES << _type << "\n";
}

// Cat::Cat(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
Cat::Cat(const Cat &cat) : Animal()
{
	std::cout << GRE"Copy Constructor called:         type" << _type << "\n" << RES;
	*this = cat;
}
// Destructor
Cat::~Cat()
{
	std::cout << GRE"Destructor called: Cat\n" << RES;

}

// Overload operators
Cat &Cat::operator= (const Cat &cat)
{
	std::cout << GRE"Assignation operator called for Cat\n" << RES;
	if (this == &cat)
		return (*this);
	this->_type = cat._type;
	return (*this);
} 



// Public member functions
void Cat::makeSound(void) const
{
	std::cout << BLU << _type << " says: 'Miaaw!'\n" << RES;
}

