/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 09:47:42 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/19 16:00:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
//////////////////////////////////
// jaka

	// const Animal *anm = new Animal();	 // This variant, destruct. is never called ???
	// const Animal *cat = new Cat();
	//const Animal *dog = new Dog();

	// anm->makeSound();
	// cat->makeSound();
	// dog->makeSound();

	// const WrongAnimal *wranm = new WrongAnimal();
	// const WrongAnimal *wrcat = new WrongCat();
	// wranm->makeSound();
	// wrcat->makeSound();


	// cat->setIdea(0, "Milk.");
	//anm->getIdea(0);
	
	// cat->setIdea(0, "Milk.");
	// cat->getIdea(0);

	//////////////////////////
	// delete anm;
	// delete cat;
////////////////////////////////////////////////////



	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				perror("Cat allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				perror("Dog allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a \033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a \033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b \033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);

	return (0);
}
