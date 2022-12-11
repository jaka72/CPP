#include "Warlock.hpp"

//Default constructor
Warlock::Warlock()
{

}



//Param. constructor
Warlock::Warlock(std::string name, std::string tl) : name(name), title(tl)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}




//Copy constructor
Warlock::Warlock(Warlock const &)
{

}

//Destructor
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
}

//Overload operator=
Warlock &Warlock::operator=(Warlock const &)
{

	return(*this);
}

//Getters

//Setters

//Public member functions

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << name << ", " << title << "!\n";
}


std::string const Warlock::getName() const
{
	return (name);
}

std::string const Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(std::string const &str)
{
	title = str;
}

