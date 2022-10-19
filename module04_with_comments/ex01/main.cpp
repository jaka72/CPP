/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 20:53:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 20:29:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>	// to convert i to a

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "colors.h"

/*
	COPY VARIANTS:
		Cat a1;
		Cat a2(a1);   /OR/	copy constr.  		==> at time of initialization  (deep copy)
		Cat a2 = a1;		copy constr.

		Cat cat3;
		cat3 = cat1;		assign= overload	==> after initialization


	--- SHALLOW VS DEEP ---

	The copied object will always have a different address. But, compiler by default performs
	a shallow copy, which means, that each member variable of both objects points to the same adress!

	Therefore, if variables are dynamic. allocated, a Deep copy must be performed via a custom copy constr.
	You need to allocate new memory for each such variable. ie: new int ...

	Apparently string does not need custom deep copy constructor, because it already manages automatically.
	Only char* needs such copying. 
	What about int* ??



	(This refers to copying the member variables, while copying the object.)

	If any of the VARIABLES of an object was dynamically allocated, it needs DEEP copy.

	Geeks: If some variables have dynamically allocated memory on heap,
		then the copied object variable will also reference the same memory location.
		This will create ambiguity, run-time errors, dangling pointers.
		Since that variable in both objects will reference to the same memory location,
		the change made by one will reflect those change in another object as well.



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





/// !!!!!!!!!!! PROBLEM, MY DECONSTRUCTORS ARE CALLED FIRST DOG, THEN BRAIN !!! SHOULD BE FIRST BRAIN !!!

int main()
{
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
	}

/////////////////////////////////////////////////////////////

	{
		// Making animals of animals in a loop
		std::cout << GRN"\n2) ............. TEST: MAKE animals OF OBJECTS 'Animal' IN A LOOP ..................\n"<<RES<<"\n";

		int	nr_animals = 5;
		if (nr_animals % 2 != 0)
			nr_animals++;
		// !!! const Animal *animals = new Animal[nr_animals]; // NO NO NO
		const Animal *animals[nr_animals];
		int half = nr_animals / 2;
		//std::cout << "half: " << half << "\n";

		//animals[0] = new Cat();


		int i = 0;
		while (i < nr_animals)
		{
			if (i < half)
			{
				std::cout << BLU"Making Cat " << i+1 << RES << "\n";
				animals[i] = new Cat();
				// check memory
			}
			else
			{
				std::cout << MAG"Making Dog " << i+1 << RES << "\n";
				animals[i] = new Dog();
				// check memory
			}
			i++;
		}

		animals[0]->makeSound();


	///////////////////////////////////////////////////////////
	//		Freeing / deleting elements of the animals
		i = 0;
		while (i < nr_animals)
		{
			std::cout << GRN"Deleting animal " << i << RES << "\n";
			delete animals[i];
			i++;
		}
	}

////////////////////////////////////////////////////////////////////////////
	
	{
		std::cout << GRN"\n...............................\n"<<RES<<"\n";
		// Cat *pussy = new Cat();
		// // Animal *pussy = new Cat();
		// pussy->makeSound();
		// Cat *pussy2(pussy);
		// // Cat pussy2 = pussy;
		// pussy2->makeSound();
		//delete pussy;
	}

	{
		std::cout << GRN"\n2) ...............................\n"<<RES<<"\n";
		// THIS IS AT THE MOMENT IRRELEVANT
		// Cat ahmed;
		// ahmed.setIdea(0, "I like milk.");
		// ahmed.getIdea(0);

		// Cat garfi = ahmed;	// invalid pointer
		// garfi = ahmed; 		// invalid pointer
		// Cat garfi(ahmed);	// invalid pointer
	}

	{
		std::cout << GRN"\n3) ............. TEST: DEEP COPY - COPY OVERLOAD CONSTRUCTOR .................."<<RES<<"\n";
		std::cout << GRN"                   The copied ideas must have different adreses \n"<<RES<<"\n";
		
		std::cout << GRN"3b) Construct Cat *white  ...............................\n"<<RES<<"\n";
		Cat *white = new Cat();

		white->setType("white");
		
		white->makeSound();
		white->setIdea(0, "I want food");
		white->setIdea(1, "I am sleepy");
		white->getIdea(0);
		white->getIdea(1);

		std::cout << GRN"\n3b) Deep Copy white to black ...............................\n"<<RES;
		Cat *black = new Cat(*white);
		
		black->setType("black");
		

		std::cout << GRN"\n3b) Print adresses of both Cats  ...............................\n"<<RES;
		
		white->makeSound();
		black->makeSound();
		
		white->getIdea(0);
		black->getIdea(0);
		
		white->getIdea(1);
		black->getIdea(1);

		delete white;
		delete black;

		
		// std::cout << GRN"\n3b) Destruct Cat *catty  ...............................\n"<<RES;
		// delete catty;
		
		// newcatty->makeSound();
		// newcatty->getIdea(0);
		// newcatty->getIdea(1);

		// std::cout << GRN"\n3b) Destruct Cat *catty  ...............................\n"<<RES;
		// delete newcatty;
	}



	{
	//	std::cout << GRN"\n4) ............. TEST: CREATE IDEAS IN THE BRAIN .................."<<RES<<"\n";

	// 	Cat *cat1 = new Cat;
	// 	int i = 0;
	// 	while (i < 100)
	// 	{
	// 		std::string str;
	// 		std::stringstream out;				// trick to do itoa()
	// 		out << i;
	// 		str = out.str();
	// 		cat1->setIdea(i, "Cat's idea " + str);
	// 		//cat1->getIdea(i);
	// 		i++;
	// 	}
	// 	delete cat1;
	}


	return (0);
}
