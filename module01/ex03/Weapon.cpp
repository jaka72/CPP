#include "Weapon.hpp"

void Weapon::setType(const std::string &type_orig)
{
    type = type_orig;
    std::cout << " Called setType: " << type << " ... \n";
}

// const std::string& Weapon::getType() const
const std::string& Weapon::getType()
{
    std::cout << " Called GETType ";
    // const std::string &typeREF = type;
    std::string &typeREF = type;
    return typeREF;
}

Weapon::Weapon(const std::string type)
{
    std::cout << "Called constructor.\n";
    setType(type);
}

Weapon::~Weapon()   
{
    // DESTRUCTOR,
    // NOT SURE IF REALLY NEEDED
    //std::cout << "Called DEstructor.\n";
}
