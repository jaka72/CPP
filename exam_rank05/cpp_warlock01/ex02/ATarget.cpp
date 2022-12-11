
#include "ATarget.hpp"

//Default constructor
ATarget::ATarget() : type()
{

}

//Param. constructor
ATarget::ATarget(std::string tp) : type(tp)
{

}



//Copy constructor
ATarget::ATarget(ATarget const &other)
{
	*this = other;
}

//Destructor
ATarget::~ATarget()
{

}

//Overload operator=
ATarget &ATarget::operator=(ATarget const &other)
{
	type = other.type;
	return(*this);
}

//Getters
std::string const & ATarget::getType() const
{
	return (type);
}


//Setters

//Public member functions
void ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!\n";
}


