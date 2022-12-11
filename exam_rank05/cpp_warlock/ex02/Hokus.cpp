#include "Hokus.hpp"

//Default constructor
Hokus::Hokus() :  ASpell("Hokus", "hokushed")  //, name("Woosh"), effects("fwooshed")
{
	//ASpell("Woosh", "fwooshed");
	std::cout << GRE"default constr (Hokus), name: " << name << "\n" RES;
}

//Param. constructor

//Copy constructor
Hokus::Hokus(Hokus const &other) : ASpell(other)
{
	*this = other;
}

//Destructor
Hokus::~Hokus()
{

}

//Overload operator=
Hokus &Hokus::operator=(Hokus const &other)
{
	this->name = other.name;
	return(*this);
}


// Pure
Hokus* Hokus::clone() const
{
	Hokus* fw = new Hokus();
	return (fw);

	// Hokus a;
	// a = Hokus.clone; 	// ??? would this work
	// delete a;



}



//Getters

//Setters

//Public member functions

