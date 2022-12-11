#include "Polymorph.hpp"

//Default constructor
Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter!")
{
	std::cout << GRE"default constr (Polymorph), name: " << name << "\n" RES;
}

//Param. constructor

//Copy constructor
Polymorph::Polymorph(Polymorph const &other) : ASpell(other)
{
	*this = other;
}

//Destructor
Polymorph::~Polymorph()
{

}

//Overload operator=
Polymorph &Polymorph::operator=(Polymorph const &other)
{
	this->name = other.name;
	return(*this);
}

//Getters

//Setters

//Public member functions

// Pure
Polymorph* Polymorph::clone() const
{
	Polymorph* pm = new Polymorph();
	return (pm);
}