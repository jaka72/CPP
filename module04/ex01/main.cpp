/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 20:53:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 16:01:17 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>	// to convert i to a

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
// #include "Brain.hpp"
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

	- Should we always be checking for success of allocation wieth 'new' ??

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

void	check_allocation(const Animal *anm)
{
	if (anm == NULL)
	{
		perror("Animal allocation failed. \n Exit\n");
		exit (1);
	}
}





int main()
{
	{	
		std::cout << "- - - Subject ex01 Example  - - - - - - - - - - -\n";
		const Animal* j = new Dog();
		delete j;
		
		const Animal* i = new Cat();
		delete i;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "- - - Create Animal Cat, set Idea - - - - - - - - -\n";
		Animal* cat = new Cat();
		cat->makeSound();
		cat->setIdea(0, "I like milk.");
		cat->getIdea(0);
		delete cat;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		std::cout << "- - - Create Cat Cat, set Idea - - - - - - - - -\n";
		Cat* cat = new Cat();
		cat->makeSound();
		cat->setIdea(0, "I like mouse.");
		cat->getIdea(0);
		delete cat;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "- - - Create Animal Dog, set Idea - - - - - - - - -\n";
		Animal* dog = new Dog();
		dog->makeSound();
		dog->setIdea(0, "I like cookie.");
		dog->getIdea(0);
		delete dog;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

/////////////////////////////////////////////////////////////


// 		TESTS TESTS TESTS //////////////////////////////////////////////////////////////////////
	
	{
		std::cout << "\n - -  - MAKE ARRAY OF Animals - - - - - - -\n\n";

		int	nr_animals = 4;
		if (nr_animals % 2 != 0)
			nr_animals--;
		else if (nr_animals <= 1 )
			nr_animals = 2;
			
		const Animal* animals[nr_animals];
		int half = nr_animals / 2;

		int i = 0;
		while (i < nr_animals)
		{
			if (i < half)
			{
				std::cout << BLU"Making Cat " << i << RES << "\n";
				animals[i] = new Cat();
				check_allocation(animals[i]);
			}
			else
			{
				std::cout << MAG"Making Dog " << i << RES << "\n";
				animals[i] = new Dog();
				check_allocation(animals[i]);
			}
			i++;
		}

		std::cout << "\nAll animals makeSound() \n";
		i = 0;
		while (i < nr_animals)
		{
			std::cout << "   " << i << " ";
			animals[i++]->makeSound();
		}
		std::cout << "\n";


		i = 0;					//		Freeing / deleting
		while (i < nr_animals)
		{
			std::cout << GRN"Deleting animal " << i << RES << "\n";
			delete animals[i];
			i++;
		}
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "\n - - - TEST DEEP COPY CAT - - - - - - - - - - - - - -\n\n";
		
		Cat* white = new Cat();
		white->setType("White");
		white->setIdea(0, "I like running");
		white->setIdea(1, "I like sleeping");
		white->setIdea(2, "I like eating");

		Cat* black = new Cat(*white);
		black->setType("Black");
		
		white->getIdea(0);
		black->getIdea(0);
		white->getIdea(1);
		black->getIdea(1);
		white->getIdea(2);
		black->getIdea(2);

		delete white;
		delete black;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{
		std::cout << "\n - - - - TEST DEEP COPY DOG - - - - - - - - - - - - - -\n\n";
		
		Dog* big = new Dog();
		big->setType("Big");
		big->setIdea(0, "I like running");
		big->setIdea(1, "I like sleeping");
		big->setIdea(2, "I like eating");

		Dog* small = new Dog(*big);
		small->setType("Small");
		
		big->getIdea(0);
		small->getIdea(0);
		big->getIdea(0);
		small->getIdea(0);
		big->getIdea(0);
		small->getIdea(0);

		delete big;
		delete small;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


////////////////////////////////////////////////////////////////////////////
	


	{
		std::cout << GRN"\n - -  TEST: CREATE ALL IDEAS IN THE BRAIN - - - - - - -"<<RES<<"\n\n";

		Cat *cat1 = new Cat;
		int i = 0;
		while (i < 100)
		{
			std::string str;
			std::stringstream out;				// trick to do itoa()
			out << i;
			str = out.str();
			//cat1->setIdea(i, "Cat's idea " + str);
			//cat1->getIdea(i);
			i++;
		}
		delete cat1;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


	return (0);
}
