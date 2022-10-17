#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
/*
	If derived object (Cat) has the same function (makeSound) as the base object (Animal),
	then makeSound() must be declared Virtual in the base class. Otherwise it is called 
	the function from base, instead of from derived object.

	(The function in the Base class must be virtual, in order to be able
		to be overriden by the derived class. Otherwise it will print  the same
		message from the function in the Base class)


	If the objects will be initialized as pointers (Animal anm = new Animal(),
	then all functions in the animal (and in derived class) must have const:  ...name() const
	To guarantee that this function will not change the object 
		??? Not sure if this is true ???



	QUESTIONS:


		Is there any difference, when initialize derived object:
				Animal	*cat = new Cat();
			VS	Cat		*cat = new Cat();



		??? If you have a virtual function in base class, then the destructor
		also has to be virtual - AND - you need to 'delete' objects in the main.
		In this case the derived class does not have to have the same
		function as virtual, and also not the destructors as virtual.
		(Without 'delete' the destructor is not called!)

		
	
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
//	const Animal *anm = new Animal();	 // This variant, destruct. is never called ???
// 	const Animal *cat = new Dog();	 // This variant, destruct. is never called ???
// 	const Animal *dog = new Cat();	 // This variant, destruct. is never called ???

// 	anm->makeSound();
// 	cat->makeSound();
// 	dog->makeSound();

// 	const WrongAnimal *wranm = new WrongAnimal();	 // This variant, destruct. is never called ???
// 	const WrongAnimal *wrcat = new WrongCat();	 // This variant, destruct. is never called ???
// 	wranm->makeSound();
// 	wrcat->makeSound();

// /////////////////////////////////
// 	delete anm;
// 	delete cat;
// 	delete dog;
// 	delete wranm;
// 	delete wrcat;


// NEW TESTING //////////////////////////////////////////////////
	{
		// Animal as non-pointer
		Animal anm1 = Animal();	// Any difference if made from Cat insteda od Animal?
		anm1.makeSound();
		anm1.getType();
		// anm1.printTest();
		// anm1.printTest_no_const();
	}
		std::cout << "\n";
	{	
		// Animal as pointer
		Animal *anm1 = new Animal();
		anm1->makeSound();
		anm1->getType();
		// anm1->printTest();
		// anm1->printTest_no_const();
		delete anm1;
	}
		std::cout << "\n";
	{
		// Cat=Cat as non-pointer
		Cat cat1 = Cat();	// If made from Cat ???
		cat1.makeSound();
		cat1.getType();
		// cat1.printTest();
		// cat1.printTest_no_const();
		// cat1.justInAnimal();
	}
		std::cout << "\n";
	{
		Cat *cat1 = new Cat();	// If made from Cat ???
		cat1->makeSound();
		cat1->getType();
		// cat1->printTest();
		// cat1->printTest_no_const();
		// cat1->justInAnimal();
		delete cat1;
		std::cout << "\n";
	}

	{
		WrongAnimal *wrAnm = new WrongAnimal();
		wrAnm->makeSound();
		wrAnm->getType();
		delete wrAnm;
		std::cout << "\n";
	}


	{
		WrongAnimal *wrCat = new WrongCat();
		wrCat->makeSound();
		wrCat->getType();
		delete wrCat;
		std::cout << "\n";
	}


	{
		Animal *dog1 = new Dog();
		dog1->makeSound();
		dog1->getType();
		delete dog1;
		std::cout << "\n";
	}





	return (0);
}
