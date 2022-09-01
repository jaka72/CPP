#include "Weapon.hpp"

void Weapon::setType(const std::string &type_orig)
{
	type = type_orig;
}

// const std::string& Weapon::getType() const	// DOES IT NEED const AT END ??? 
const std::string& Weapon::getType()
{
//  const std::string &typeREF = type;			// DOES IT NEED const IN FRONT ???
	      std::string &typeREF = type;			//   BECAUSE FUNCTION RETURNS const 
	return typeREF;
}

Weapon::Weapon(const std::string type)
{
	setType(type);
}

Weapon::~Weapon()   	// DESTRUCTOR
{
}
