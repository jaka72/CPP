// #include <cstdio>
// #include <cstdlib>
// #include <error.h>
#include "Cat.hpp"


// ??? IT IS NOT CALLED HAVE ANY EFFECT
Cat::Cat() : Animal()
{
	this->_type = "Cat";  
	std::cout << GRE"Default Constructor: Cat,    type " << RES << this->_type << "\n";
	
	this->_brain = new Brain();	// OR this->brain =
	if (this->_brain == NULL)
	{
		perror("Memory allocation for Cat Brain failed\n");
		std::cerr << "Exiting the process now." << std::endl;
		exit (1);
	}
}



// Copy constructor
// Cat::Cat(const Cat &cat) : Animal(cat)
Cat::Cat(const Cat &cat) : Animal()
{
	this->_type = "Cat";  
	std::cout << GRE"Copy Constructor:            type " << _type << "\n" << RES;
	*this = cat;
}



// Overload operators
Cat &Cat::operator= (const Cat &cat)
{
	// std::cout << YEL"a)\n" << RES;
	std::cout << GRE"Overload the Assign= operator for Cat\n" << RES;
	if (this == &cat)
		return (*this);
	this->_type = cat._type;

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
	*this->_brain = *cat._brain;	// WITHOUT THE * YOU CANNOT USE delete newcatty
									//  IF newcatty IS MADE VIA COPY CONSTR !!!
									//  like:  Cat *newcatty = new Cat(*catty) 
	
	return (*this);
} 



// Destructor
Cat::~Cat()
{
	std::cout << GRE"Destructor: Cat\n" << RES;
	delete (this->_brain);	// OR this->brain;
}


// Public member functions
void Cat::makeSound(void) const
{
	std::cout << BLU << _type << " says: 'Miaaw!'\n" << RES;
}

// Setter
 // THIS WAS ERROR,
// passing ‘const Cat’ as ‘this’ argument discards qualifiers [-fpermissive]
// THIS PROBLEM HAPPEND BEFORE, SOMETHING TO DO WITH const ???! !!!!
// SOMETING NOT BEING ABLE TO PROCESS, IT THERE IS NO const ...
void Cat::setIdea(int n, std::string idea) const 
{
	this->_brain->setIdea(n, idea);
}


// Getter
void Cat::getIdea(int n) const
{
	std::cout << "   Cat's idea " << n << ": '" << _brain->getIdea(n) << "'    ";
	std::cout << "Location: " << _brain->getIdeaAdres(n) << "'\n";
}
