#include "BrickWall.hpp"

//Default constructor
BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{

}

//Param. constructor

//Copy constructor
BrickWall::BrickWall(BrickWall const &other) : ATarget(other)
{
	*this = other;
}

//Destructor
BrickWall::~BrickWall()
{

}

//Overload operator=
BrickWall &BrickWall::operator=(BrickWall const &other)
{
	this->type = other.type;
	return(*this);
}

//Getters

//Setters

//Public member functions

// pure
BrickWall* BrickWall::clone() const
{
	return (new BrickWall());
}
