#include "Dummy.hpp"

//Default constructor
Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}

//Param. constructor

//Copy constructor
Dummy::Dummy(Dummy const &other) : ATarget(other)
{

}

//Destructor
Dummy::~Dummy()
{

}

//Overload operator=
Dummy &Dummy::operator=(Dummy const &)
{

	return(*this);
}

//Getters

//Setters

//Public member functions

// pure 
ATarget *Dummy::clone() const
{
	return (new Dummy(*this));
}