#include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


Animal::Animal(): _type("default")
{
	//test = 33;
	std::cout << GRE"Constructor Animal called, type " << RES << _type << "\n";
}

// Animal::Animal(std::string &type)
// {
// 	std::cout << GRE"Constructor called for type" << type << "\n" << RES;
// 	// _type = type;
// }

// // Copy constructor
// Animal::Animal(const Animal &animal)
// {
// 	std::cout << GRE"Constructor Copy called for type" << _type << "\n" << RES;
// 	*this = animal;
// }
// // Destructor
// Animal::~Animal()
// {
// 	std::cout << GRE"Destructor Animal called\n" << RES;

// }

// // Overload operators
// Animal &Animal::operator= (const Animal &animal)
// {
// 	std::cout << GRE"Assignation operator called for Animal\n" << RES;
// 	if (this == &animal)
// 		return (*this);
// 	this->_type = animal._type;
// 	return (*this);
// } 

// // // Public member functions
// // void makeSound(void)
// // {

// // }


// void Animal::printTest(void)
// {
// 	std::cout << "Test from Animal : " << test << "\n";
// }

