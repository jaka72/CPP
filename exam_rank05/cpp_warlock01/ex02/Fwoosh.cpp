#include "Fwoosh.hpp"

//Default constructor
Fwoosh::Fwoosh() : ASpell("Foosh", "fwooshed")
{

}

//Param. constructor
Fwoosh::Fwoosh(std::string name, std::string effects) : ASpell(name, effects)
{

}


//Copy constructor
Fwoosh::Fwoosh(Fwoosh const &other) : ASpell(other)
{
	//*this = other;   // maybe not needed in children, because of the above
						// init list, will not error
}

//Destructor
Fwoosh::~Fwoosh()
{

}

//Overload operator=
Fwoosh &Fwoosh::operator=(Fwoosh const &)
{
	// name = other.name;
	// effects = other.effects;
	return(*this);
}

//Getters

//Setters

//Public member functions
ASpell* Fwoosh::clone() const
{
	return (new Fwoosh(*this));
}


