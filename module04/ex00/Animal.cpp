#include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"


Animal::Animal()
{
	_type = "default";
	test = 33;
	std::cout << GRE"Default Constructor called: Animal, type " << RES << _type << "\n";
}

// Animal::Animal(std::string &type)
// {
// 	std::cout << GRE"String Constructor called, Animal, type" << type << "\n" << RES;
// 	// _type = type;
// }

// Copy constructor
Animal::Animal(const Animal &animal)
{
	std::cout << GRE"Copy Constructor called, Animal, type" << _type << "\n" << RES;
	*this = animal;
}
// Destructor
Animal::~Animal()
{
	std::cout << GRE"Destructor called, Animal\n" << RES;

}

// Overload operators
Animal &Animal::operator= (const Animal &animal)
{
	std::cout << GRE"Assignation operator called for Animal\n" << RES;
	if (this == &animal)
		return (*this);
	this->_type = animal._type;
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
void Animal::makeSound(void) const
{
	std::cout << BLU"Called makeSound() for class Animal (no sound)\n" << RES;
}


// void Animal::printTest(void)
// {
// 	std::cout << "Test from Animal : " << test << "\n";
// }

