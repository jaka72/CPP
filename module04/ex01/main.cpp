#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "colors.h"

/*
	QUESTIONS:

	Never called the destructor:  ???
	Animal a();							// No call to constr or destr. ???
	const Animal *anm = new Animal();	// This variant, destruct. is never called ???

	Which perror ??
		perror("...");
		std::cerr << "...";
		std::perror("...");
		std::strerror(errno);

	Inherit a class VS Create a class (new Brain) inside a different class (Catt)

	- Does this variant need to check for failed alloc?
						const Cat *cat = new Cat();

*/

/*
	Creating an instance of a class inside another class:
		(Brain inside Cat)
	In cat.hpp is private Brain *br
	In cat.cpp is this->brain = new Brain()  !!NOT Brain *br = new Brain()
*/


int main()
{
	//const Animal *anm = new Animal();	 
	// const Animal *cat = new Cat();	// Animal ==> *cat works, but only without calling setIdea()
										// 	because Animal does not have it.
										// 		Then it needs to be Cat ==> *cat

	//const Cat *cat = new Cat();
	//const Animal *dog = new Dog();

	//anm->makeSound();
	//cat->makeSound();
	// dog->makeSound();

	// const WrongAnimal *wranm = new WrongAnimal();
	// const WrongAnimal *wrcat = new WrongCat();
	// wranm->makeSound();
	// wrcat->makeSound();


	//cat->setIdea(0, "I like milk.");
	//cat->getIdea(0);
	
	// cat->setIdea(0, "Milk.");
	// cat->getIdea(0);

	//////////////////////////
	//delete anm;
	//delete cat;
	// delete dog;
	// delete wranm;
	// delete wrcat;

/////////////////////////////////////////////////////////////
	// Making array of animals in a loop
	std::cout << GRN"\n2) ............. TEST: MAKE ARRAY OF OBJECTS 'Animal' IN A LOOP ..................\n"<<RES<<"\n";

	int	nr_animals = 4;
	// !!! const Animal *array = new Animal[nr_animals]; // NO NO NO
	const Animal *array[nr_animals];
	int half = nr_animals / 2;
	std::cout << "half: " << half << "\n";

	//array[0] = new Cat();


	int i = 0;
	while (i < nr_animals)
	{
		if (i < half)
		{
			std::cout << BLU"Making Cat " << i+1 << RES << "\n";
			array[i] = new Cat();
		}
		else
		{
			std::cout << MAG"Making Dog " << i+1 << RES << "\n";
			array[i] = new Dog();
		}
		i++;
	}

	array[0]->makeSound();




///////////////////////////////////////////////////////////
//		Freeing / deleting elements of the array
	i = 0;
	while (i < nr_animals)
	{
		std::cout << GRN"Deleting array element " << i << RES << "\n";
		delete array[i];
		i++;
	}

////////////////////////////////////////////////////////////////////////////
	std::cout << GRN"\n...............................\n"<<RES<<"\n";
	// Cat *pussy = new Cat();
	// // Animal *pussy = new Cat();
	// pussy->makeSound();
	// Cat *pussy2(pussy);
	// // Cat pussy2 = pussy;
	// pussy2->makeSound();
	//delete pussy;


	std::cout << GRN"\n2) ...............................\n"<<RES<<"\n";
	// THIS IS AT THE MOMENT IRRELEVANT
	// Cat ahmed;
	// ahmed.setIdea(0, "I like milk.");
	// ahmed.getIdea(0);

	// Cat garfi = ahmed;	// invalid pointer
	// garfi = ahmed; 		// invalid pointer
	// Cat garfi(ahmed);	// invalid pointer



	std::cout << GRN"\n3) ............. TEST: COPY OVERLOAD CONSTRUCTOR .................."<<RES<<"\n";
	std::cout << GRN"   The copied ideas must have different adreses \n"<<RES<<"\n";
	
	std::cout << GRN"3b) Construct Cat *catty  ...............................\n"<<RES<<"\n";
	Cat *catty = new Cat();
	catty->makeSound();
	catty->setIdea(0, "abc");
	catty->setIdea(1, "def");
	catty->getIdea(0);
	catty->getIdea(1);

	std::cout << GRN"\n3b) Deep Copy catty to newcatty ...............................\n"<<RES;
	Cat *newcatty = new Cat(*catty);
	
	std::cout << GRN"\n3b) Destruct Cat *catty  ...............................\n"<<RES;
	delete catty;
	
	newcatty->makeSound();
	newcatty->getIdea(0);
	newcatty->getIdea(1);

	std::cout << GRN"\n3b) Destruct Cat *catty  ...............................\n"<<RES;
	delete newcatty;

	return (0);
}
