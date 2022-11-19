/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 14:48:36 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/05 13:43:25 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Default constructor
// Dog::Dog() : Animal()
// {
// 	_type = "Dog";
// 	std::cout << GRE"   Default Constructor: Dog, type " << RES << this->_type << "\n";

// 	// this->_brain = new Brain();
// 	// if (this->_brain == NULL)
// 	// {
// 	// 	perror("Memory allocation for Cat Brain failed\n");
// 	// 	std::cerr << "Exiting the process now." << std::endl;
// 	// 	exit (1);
// 	// }
// }


// // Parameterized constr.
// Dog::Dog(std::string type) : Animal()
// {
// 	std::cout << GRE"   Param. constructor, Dog, type: " << RES << type << "\n" << RES;
// 	this->_type = type;
// }


// // Copy constructor
// Dog::Dog(const Dog &dog) : Animal()
// {
// 	_type = "Dog";

// 	std::cout << GRE"   Copy Constructor:             type " << RES << _type << "\n" << RES;
// 	*this = dog;
// }



// // Overload operators
// Dog &Dog::operator= (const Dog &dog)
// {
// 	std::cout << GRE"   Overload the Assign= operator for Dog\n" << RES;
// 	if (this == &dog)
// 		return (*this);
// 	this->_type = dog._type;

// 	// _brain = new Brain();
	
// 	// if (_brain == NULL)
// 	// {
// 	// 	perror("Memory allocation for Cat Brain failed\n");
// 	// 	std::cerr << "Exiting the process now." << std::endl;
// 	// 	exit (1);
// 	// }

// 	// *this->_brain = *dog._brain;

// 	return (*this);
// } 



// // Destructor
// Dog::~Dog()
// {
// 	//delete (this->_brain);
// 	std::cout << GRE"   Destructor, Dog\n" << RES;
// }


// // Public member functions
// void Dog::makeSound(void) const
// {
// 	std::cout << BLU"   Dog (type " << _type << ") says: 'Wooof!'\n" << RES;
// }


// // Setters
// void Dog::setIdea(int, std::string) 
// {
// 	// this->_brain->setIdea(n, idea);
// }


// void Dog::setType(std::string type)
// {
// 	this->_type = type;
// }


// // Getters
// void Dog::getIdea(int) const
// {
// 	// std::cout << BLU"   Dog (type " << _type << ") getIdea " << n << ": '" << _brain->getIdea(n);
// 	// std::cout << "'    Address: " << _brain->getIdeaAdres(n) << "'\n" << RES;
// }


// std::string Dog::getType() const
// {
// 	std::cout << BLU"   Cat getType: " << _type << "\n" << RES;
// 	return this->_type;
// }
