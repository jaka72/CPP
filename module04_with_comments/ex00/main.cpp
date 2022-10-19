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
	// {
	// 	std::cout << "- - - Create Animal (as non-pointer) - - -\n";
	// 	Animal anm1;
	// 	//anm1.setType("Mammal");
	// 	anm1.makeSound();
	// 	anm1.getType();
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	// {
	// 	std::cout << "- - - Duplicate Animal (as non-pointer) - - -\n";
	// 	Animal anm1("Mammal");
	// 	Animal anm2(anm1);
	// 	anm2.setType("Rodent");
	// 	anm1.makeSound();
	// 	anm2.makeSound();
	// 	anm1.getType();
	// 	anm2.getType();
	// }
	//	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{	
		std::cout << "- - - Create Animals (as const pointer) - - -\n";
		const Animal *anm1 = new Animal();
		const Animal *anm2 = new Animal("Mammal");
		const Animal *anm3 = new Animal("Rodent");
		//anm2->setType("bird");
		anm1->getType();
		anm2->getType();
		anm3->getType();
		anm1->makeSound();
		anm2->makeSound();
		anm3->makeSound();
		// anm->printTest();
		// anm->printTest_no_const();
		delete anm1;
		delete anm2;
		delete anm3;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{	
		std::cout << "- - - Create and copy Animals (as const pointers) - - -\n";
		const Animal *anm1 = new Animal();
		const Animal *anm2 = new Animal("Mammal");
		const Animal *anm3 = new Animal(*anm2);
		anm1->getType();
		anm2->getType();
		anm3->getType();
		anm1->makeSound();
		anm2->makeSound();
		anm3->makeSound();
		// anm3->setType("Rodent"); // Not possible, it is const
		delete anm1;
		delete anm2;
		delete anm3;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "- - - Create Cat - - - - - - - - - - - - - - -\n";
		const Animal *cat1 = new Cat();	// made from Animal
		cat1->makeSound();
		cat1->getType();
		delete cat1;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "- - - Create Cat with type - - - -  - - - - - - - - - -\n";
		const Animal *cat1 = new Cat("Lizzy");	// made from Animal
		cat1->makeSound();
		cat1->getType();
		delete cat1;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "- - - Create Dog - - - - - - - - - - - - - -\n";
		const Animal *dog1 = new Dog();	// made from Animal
		dog1->makeSound();
		dog1->getType();
		delete dog1;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	
	// // 	std::cout << "\n";
	// // {
	// // 	Cat *cat1 = new Cat();	// If made from Cat ???
	// // 	cat1->makeSound();
	// // 	cat1->getType();
	// // 	// cat1->printTest();
	// // 	// cat1->printTest_no_const();
	// // 	// cat1->justInAnimal();
	// // 	delete cat1;
	// // 	std::cout << "\n";
	// // }

	{
		std::cout << "- - - Create WrongAnimal - - - - - - - - - -\n";
		const WrongAnimal *wrAnm = new WrongAnimal();
		wrAnm->makeSound();
		wrAnm->getType();
		delete wrAnm;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		std::cout << "- - - Create WrongCat from WrongAnimal - - -\n";
		const WrongAnimal *wrCat = new WrongCat();
		wrCat->makeSound();
		wrCat->getType();
		delete wrCat;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		std::cout << "- - - Create WrongCat from WrongCat - - - - - -\n";
		const WrongCat *wrCat = new WrongCat();
		wrCat->makeSound();
		wrCat->getType();
		delete wrCat;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return (0);
}
