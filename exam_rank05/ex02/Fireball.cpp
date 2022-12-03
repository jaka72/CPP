#include "Fireball.hpp"

//Default constructor
Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp!")
{
	std::cout << GRE"default constr (Fireball), name: " << name << "\n" RES;
}

//Param. constructor

//Copy constructor
Fireball::Fireball(Fireball const &other) : ASpell(other)
{
	*this = other;
}

//Destructor
Fireball::~Fireball()
{

}

//Overload operator=
Fireball &Fireball::operator=(Fireball const &other)
{
	this->name = other.name;
	return(*this);
}

//Getters

//Setters

//Public member functions


// Pure
Fireball* Fireball::clone() const
{
	Fireball* bw = new Fireball();
	return (bw);
}
