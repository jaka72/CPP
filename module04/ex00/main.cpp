/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 10:19:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 10:43:23 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

/*
	If derived object (Cat) has the same function (makeSound) as the base object (Animal),
	then makeSound() must be declared Virtual in the base class. Otherwise it is called 
	the function from base, instead of from derived object.

	(The function in the Base class must be virtual, in order to be able
		to be overriden by the derived class. Otherwise it will print  the same
		message from the function in the Base class)


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
	{
		std::cout << "- - - Subject ex00 Example - - - - - - - - -\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		
		delete meta;
		delete i;
		delete j;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{	
		std::cout << "- - - Create Animals (as const pointer) - - -\n";
		const Animal *anm1 = new Animal();
		const Animal *anm2 = new Animal("Mammal");
		const Animal *anm3 = new Animal("Rodent");
		anm1->getType();
		anm2->getType();
		anm3->getType();
		anm1->makeSound();
		anm2->makeSound();
		anm3->makeSound();
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
		const Animal *cat1 = new Cat("White");	// made from Animal
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
