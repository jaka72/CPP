#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
	QUESTIONS:
*/

int main()
{
	// const Animal a;
	// Animal a();						// No call to constr or destr. ???
	const Animal *a = new Animal();	 // This variant, destruct. is never called ???
	const Animal *b = new Dog();	 // This variant, destruct. is never called ???
	const Animal *c = new Cat();	 // This variant, destruct. is never called ???

	//Cat d;

	// Dog d;

	//a.printTest();
	//c.printTest();

	//c.makeSound();
	//a.makeSound();
	return (0);
}
