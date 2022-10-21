/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 21:19:37 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 13:31:51 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal()
{
	this->_type = "Cat";  
	std::cout << GRE"   Default Constructor: Cat,    type " << RES << this->_type << "\n";
	
	this->_brain = new Brain();

	if (this->_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exit" << "\n";
		exit (1);
	}
}

// Parameterized constr.
Cat::Cat(std::string type)
{
	std::cout << GRE"   Param. constructor, Cat, type: " << RES << type << "\n" << RES;
	this->_type = type;

	this->_brain = new Brain();

	if (this->_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exit" << "\n";
		exit (1);
	}
}


// Copy constructor
Cat::Cat(const Cat &cat) : Animal()
{
	std::cout << GRE"   Copy Constructor:            type " << RES << _type << "\n" << RES;
	*this = cat;
}



// Overload operators
Cat &Cat::operator= (const Cat &cat)
{
	std::cout << GRE"   Overload the Assign= operator for Cat\n" << RES;
	if (this == &cat)
		return (*this);
		
	this->_type = cat._type;

	_brain = new Brain();
	
	if (_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exiting the process now." << std::endl;
		exit (1);
	}

	*this->_brain = *cat._brain;
	
	return (*this);
} 


// Destructor
Cat::~Cat()
{
	delete (this->_brain);
	std::cout << GRE"   Destructor: Cat\n" << RES;
}


// Public member functions
void Cat::makeSound(void) const
{
	std::cout << BLU"   Cat (type " << _type << ") says: 'Miaaw!'\n" << RES;
}

// Setter
void Cat::setIdea(int n, std::string idea)
{
	this->_brain->setIdea(n, idea);
}


void Cat::setType(std::string type)
{
	this->_type = type;
}


// Getter
std::string Cat::getType() const
{
	std::cout << BLU"   Cat getType: " << _type << "\n" << RES;
	return this->_type;
}


// Getter
void Cat::getIdea(int n) const
{
	std::cout << BLU"   Cat (type " << _type << ") getIdea " << n << ": '" << _brain->getIdea(n);
	std::cout << "'    Address: " << _brain->getIdeaAdres(n) << "'\n" << RES;
}
