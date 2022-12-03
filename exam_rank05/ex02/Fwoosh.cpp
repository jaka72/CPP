#include "Fwoosh.hpp"

//Default constructor
Fwoosh::Fwoosh() :  ASpell("Fwoosh", "fwooshed")  //, name("Woosh"), effects("fwooshed")
{
	//ASpell("Woosh", "fwooshed");
	std::cout << GRE"default constr (Woosh), name: " << name << "\n" RES;
}

//Param. constructor

//Copy constructor
Fwoosh::Fwoosh(Fwoosh const &other) : ASpell(other)
{
	*this = other;
}

//Destructor
Fwoosh::~Fwoosh()
{

}

//Overload operator=
Fwoosh &Fwoosh::operator=(Fwoosh const &other)
{
	this->name = other.name;
	return(*this);
}


// Pure
Fwoosh* Fwoosh::clone() const
{
	Fwoosh* fw = new Fwoosh();
	return (fw);

	// Fwoosh a;
	// a = Fwoosh.clone; 	// ??? would this work
	// delete a;
}



//Getters

//Setters

//Public member functions

