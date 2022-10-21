/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:48:36 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/10/19 20:21:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << GRE"   Default Constructor: Dog,    type " << RES << this->_type << "\n";

	this->_brain = new Brain();	// OR this->brain =
	if (this->_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exiting the process now." << std::endl;
		exit (1);
	}
}


// Parameterized constr.
Dog::Dog(std::string type) : Animal()
{
	std::cout << GRE"   Param. constructor, Dog, type: " << RES << type << "\n" << RES;
	this->_type = type;
}


// Copy constructor
Dog::Dog(const Dog &dog) : Animal()	// !! without dog in Animal(dog)
{
	_type = "Dog";

	std::cout << GRE"   Copy Constructor:             type" << RES << _type << "\n" << RES;
	*this = dog;
}




// Overload operators
Dog &Dog::operator= (const Dog &dog)
{
	std::cout << GRE"   Overload the Assign= operator for Dog\n" << RES;
	if (this == &dog)
		return (*this);
	this->_type = dog._type;

	_brain = new Brain();	// OR this->brain =
							// iS DECLARED AS POINTER *_brain
	
	if (_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exiting the process now." << std::endl;
		exit (1);
	}

	//  HERE THE _ideas ARE COPIED 1by1 INTO NEW ALLOCATED POINTER _brain
	// this->_brain = cat._brain;	// HERE IT WAS A PROBLEM !!!
	*this->_brain = *dog._brain;	// WITHOUT THE * YOU CANNOT USE delete newcatty
									//  IF newcatty IS MADE VIA COPY CONSTR !!!
									//  like:  Cat *newcatty = new Cat(*catty) 

	return (*this);
} 



// Destructor
Dog::~Dog()
{
	std::cout << GRE"   Destructor, Dog\n" << RES;
	delete (this->_brain);	// OR this->brain;
}


// Public member functions
void Dog::makeSound(void) const
{
	std::cout << BLU << _type << " says: 'Wooof!'\n" << RES;
}


// Setters
 // THIS WAS ERROR,
// passing ‘const Cat’ as ‘this’ argument discards qualifiers [-fpermissive]
// THIS PROBLEM HAPPEND BEFORE, SOMETHING TO DO WITH const ???! !!!!
// SOMETING NOT BEING ABLE TO PROCESS, IT THERE IS NO const ...
void Dog::setIdea(int n, std::string idea) const 
{
	this->_brain->setIdea(n, idea);
}


void Dog::setType(std::string type)
{
	this->_type = type;
}


// Getters
void Dog::getIdea(int n) const
{
	std::cout << "   Dog's idea " << n << ": '" << _brain->getIdea(n);
	std::cout << "'    Address: " << _brain->getIdeaAdres(n) << "'\n";
}


std::string Dog::getType() const
{
	std::cout << BLU"   Cat getType: " << _type << "\n" << RES;
	return this->_type;
}

