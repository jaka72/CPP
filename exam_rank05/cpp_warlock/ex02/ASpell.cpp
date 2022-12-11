#include "ASpell.hpp"

//Default constructor
ASpell::ASpell()
{
	std::cout << GRE"default constr (ASpell), name: " << name << "\n" RES;
}


ASpell::ASpell(std::string nm, std::string eff) : name(nm), effects(eff)
{

}

//Param. constructor

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
	this->name = other.name;
	return(*this);
}

//Getters

//Setters

//Public member functions
void ASpell::launch(const ATarget& trg)
{
	trg.getHitBySpell(*this);
}


std::string ASpell::getEffects() const
{
	return (this->effects);
}

std::string ASpell::getName() const
{
	//std::cout << "called getNmae()\n";
	return (this->name);
}
