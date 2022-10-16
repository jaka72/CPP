#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GRE"Constructor Default called for type " << RES << _type << "\n";
}

// // Dog::Dog(std::string &type)
// // {
// // 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// // 	// _type = type;
// // }

// // Copy constructor
// Dog::Dog(const Dog &dog) //: Animal(cat)
// {
// 	std::cout << GRE"Constructor Copy called for type" << _type << "\n" << RES;
// 	*this = dog;
// }
// // Destructor
// Dog::~Dog()
// {
// 	std::cout << GRE"Destructor Dog called\n" << RES;

// }

// // Overload operators
// Dog &Dog::operator= (const Dog &dog)
// {
// 	std::cout << GRE"Assignation operator called for Dog\n" << RES;
// 	if (this == &dog)
// 		return (*this);
// 	this->_type = dog._type;
// 	return (*this);
// } 



// // Public member functions
// void Dog::makeSound(void)
// {
// 	std::cout << BLU << _type << " says: 'Miaaw!'\n" << RES;
// }

