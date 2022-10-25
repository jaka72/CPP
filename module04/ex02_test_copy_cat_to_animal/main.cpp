/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 20:53:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/23 11:48:34 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

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
		std::cout << "- - - Try creating object of abstract class - - - - - - -\n";
		// Animal  anm1;						// not possible
		// Animal *anm2 = new Animal();			// not possible
		// const Animal* j = new Animal();		// not possible
	}
	 	std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	

	{
		std::cout << "- - - Beyond Subject - - - - - - - - - - - -  - -  - - - - -\n";
		std::cout << "- - - Shallow copy (just the address) - - - - - - - - - - - - -\n";

		// const Animal* cat1 = new Cat();		// Error, const apparently can't copy its address
		Animal* cat1 = new Cat();
		
		// A)
		std::cout << "A) ......\n";
		Animal* cat2(cat1);	// cat2 IS JUST A POINTER, HAS NO SEPARATE MEMORY. IDEAS WILL BE THE SAME AS cat1
							// No constructor called
		
		// cat1->getIdea(0);
		// cat2->getIdea(0);
		// cat2->makeSound();
		// cat1->setIdea(0, "cat1 idea 0");
		// cat1->getIdea(0);
		cat2->getIdea(0);
		
		std::cout << "B) ......\n";
		
		// B)
		// Cat    cat4(*cat1);	// OK, calls constr Cat(Animal &cpy).    Cat4 is non-pointer Animal, has brain
		   Animal cat3(*cat1);	// OK, calls constr Animal(Animal &cpy). Cat3 is non-pointer Animal, no brain

		cat3.getIdea(0);	// Does nothing, because it is Animal
		cat3.setIdea(0, "cat3 idea 0");
		cat3.getIdea(0);


		// C)
		std::cout << "C) ......\n";
		// Animal cat3(*cat1);	// OK, calls constr Animal(Animal &cpy). Cat3 is non-pointer Animal, no brain
		   Cat    cat4(*cat1);	// OK, calls constr Cat(Animal &cpy).    Cat4 is non-pointer Animal, has brain
		
		cat4.getIdea(0);	// Prints, because cat4 is Cat
		cat4.setIdea(0, "cat3 idea 0");
		cat4.getIdea(0);

		/*	D)
			Entity          Value
			Cat* cat3 = new Animal();	Not possible!
			Error: Value of type Animal* cannot be used to initialize an entity of type Cat*
		*/
		
		std::cout << "E) ......\n";
		Animal cat11;
		Cat cat5(cat11);	// Copy value from non-pointer
		//Cat cat6(*cat1);	// Copy value from pointer

		// cat11.setIdea(0, "cat11 idea 0");	// No, Animal has no brain
		cat5.setIdea(0, "cat5 idea 0");
		//cat6.setIdea(0, "cat6 idea 0");
		cat11.getIdea(0);	// No, Animal has no brain
		cat5.getIdea(0);	// Prints, because cat4 is Cat
		// cat6.getIdea(0);	// Prints, because cat4 is Cat
		
	
		delete cat1;
	}
	 	std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";

	{
		// std::cout << "- - - Beyond Subject - - - - - - - - - - - -  - - - - -\n";
		// std::cout << "- - - Constructor Cat via Animal (parent as argument) - - - - -\n";
		// /* THE DIFFERENCE
		// 	Animal* cat1 = new  Cat();   /VS/	-Runs a polimorf function from Animal, not from Cat, unless it is virtual in Animal
		// 	Animal* cat1 = new  Animal();		-Runs always a polimorf function from Animal (virtual or not)
		// */
		
		// Animal* cat1 = new  Cat();
		// Animal* cat2 = new  Cat(*cat1);  // Cat has now a custom constructor, which takes Animal as arg
				
		// cat1->setType("Cat1");
		// cat1->test00();
		
		// cat1->getIdea(0);
		// cat2->getIdea(0);
		// cat1->setIdea(0, "cat1 idea 0");
		// cat1->getIdea(0);
		// cat2->getIdea(0);

		//delete cat1;
		//delete cat2;
	}
	





	/*
	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	{	
		std::cout << "- - - Create derived object from abstract class - - - - -\n";
		const Animal* cat1 = new Cat();
		delete cat1;

		const Animal* dog1 = new Dog();
		delete dog1;
	}
	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - -\n\n\n";


		
	
	/////////////////////////////////////////////////////////////
	
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
				animals[i] = new(std::nothrow) Cat();
				check_allocation(animals[i]);
			}
			else
			{
				std::cout << MAG"Making Dog " << i << RES << "\n";
				animals[i] = new(std::nothrow) Dog();
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

	////////////////////////////////////////////////////////////////////////////

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
			std::stringstream out;				// trick to use as itoa()
			out << i;
			str = out.str();
			//cat1->setIdea(i, "Cat's idea " + str);
			//cat1->getIdea(i);
			i++;
		}
		delete cat1;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n";
	*/
	//system ("leaks a.out");
	return (0);
}
