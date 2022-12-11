

#include "Warlock.hpp"

//Constructors
Warlock::Warlock()
{	}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}


Warlock::Warlock(Warlock const &other)
{

}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done.\n";
	// std::cout << this->getName() << ": My job here is done.\n";
}

Warlock &Warlock::operator= (Warlock const &other)
{
	return(*this);
}


// Getters
const std::string& Warlock::getName() const
{
	return (_name);
}

const std::string& Warlock::getTitle() const
{
	return (_title);
}

// Setters
void Warlock::setTitle(std::string str)
{
	_title = str;
}



// Member functions
void Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!\n"; 

}

