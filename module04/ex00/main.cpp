#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
/*
	QUESTIONS:

	- Should these be deleted at the end?
			const Animal *cat = new Animal();
			delete cat;		???
		If you have a virtual function in base class, then the destructor
		also has to be virtual - AND - you need to 'delete' objects in the main.
		In this case the derived class does not have to have the same
		function as virtual, and also not the destructors as virtual.
		(Without 'delete' the destructor is not called!)

		(The function in the Base class must be virtual, in order to be able
		to be overriden by the derived class. Otherwise it will print  the same
		message from the function in the Base class)
	
*/

int main()
{
	// const Animal a;
	// Animal a();						// No call to constr or destr. ???
	// Cat e;
	// e.makeSound();
	// Dog d;
	//a.printTest();
	//c.printTest();

////////////////////////
	const Animal *anm = new Animal();	 // This variant, destruct. is never called ???
	const Animal *cat = new Dog();	 // This variant, destruct. is never called ???
	const Animal *dog = new Cat();	 // This variant, destruct. is never called ???

	anm->makeSound();
	cat->makeSound();
	dog->makeSound();

	const WrongAnimal *wranm = new WrongAnimal();	 // This variant, destruct. is never called ???
	const WrongAnimal *wrcat = new WrongCat();	 // This variant, destruct. is never called ???
	wranm->makeSound();
	wrcat->makeSound();

/////////////////////////////////
	delete anm;
	delete cat;
	delete dog;
	delete wranm;
	delete wrcat;

	return (0);
}
