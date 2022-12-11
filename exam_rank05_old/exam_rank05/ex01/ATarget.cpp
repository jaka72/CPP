#include "ATarget.hpp"

//Default constructor
ATarget::ATarget()
{

}
ATarget::ATarget(std::string tp) : type(tp)
{
}



//Param. constructor

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
	this->type = other.type;
	return(*this);
}

//Getters

//Setters

//Public member functions
void ATarget::getHitBySpell(const ASpell& asp) const
{
	std::cout << GRN << getType() << " has been " << asp.getEffects() << "!\n" RES;
}


const std::string& ATarget::getType() const
{
	return (this->type);
}
