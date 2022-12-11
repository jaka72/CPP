#include "Dummy.hpp"

//Default constructor
Dummy::Dummy() : ATarget("Target Practice Dummy") // type("Target Practice Dummy")
{

}

//Param. constructor

//Copy constructor
Dummy::Dummy(Dummy const &other) : ATarget(other)
{
	*this = other;
}

//Destructor
Dummy::~Dummy()
{

}

//Overload operator=
Dummy &Dummy::operator=(Dummy const &other)
{
	this->type = other.type;
	return(*this);
}


Dummy* Dummy::clone() const
{
	return (new Dummy());
}


//Getters

//Setters

//Public member functions

