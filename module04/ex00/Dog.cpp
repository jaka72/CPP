#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GRE"Default Constructor called:         type " << RES << _type << "\n";

}

// Dog::Dog(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
Dog::Dog(const Dog &dog) : Animal()
{
	std::cout << GRE"Copy Constructor Copy called:        type" << _type << "\n" << RES;
	*this = dog;
}
// Destructor
Dog::~Dog()
{
	std::cout << GRE"Destructor called, Dog\n" << RES;

}

// Overload operators
Dog &Dog::operator= (const Dog &dog)
{
	std::cout << GRE"Assignation operator called for Dog\n" << RES;
	if (this == &dog)
		return (*this);
	this->_type = dog._type;
	return (*this);
} 



// Public member functions
void Dog::makeSound(void) const
{
	std::cout << BLU << _type << " says: 'Wooof!'\n" << RES;
}