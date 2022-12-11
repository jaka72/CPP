#include "ASpell.hpp"

//Default constructor
ASpell::ASpell() : name(), effects()
{

}

//Param. constructor
ASpell::ASpell(std::string nm, std::string eff) : name(nm), effects(eff)
{

}


//Copy constructor
ASpell::ASpell(ASpell const &other)
{
	*this = other;
}

//Destructor
ASpell::~ASpell()
{

}

//Overload operator=
ASpell &ASpell::operator=(ASpell const &other)
{
	// check here for the correct checking!
	name = other.name;
	effects = other.effects;
	return(*this);
}

//Getters
std::string ASpell::getName() const
{
	return (name);
}


std::string ASpell::getEffects() const
{
	return (effects);
}

//Setters

//Public member functions


void ASpell::launch(ATarget const & target) const // I set to const both functions???
{
	target.getHitBySpell(*this);
}



// // pure
// ASpell* ASpell::clone() const		// not needed in parent
// {
// }