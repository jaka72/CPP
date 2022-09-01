#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name_orig) : name(name_orig)
{
    //name = name_orig;
    wp = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &wp_orig)
{
    wp = &wp_orig;  // MUST BE WITH &    BECAUSE wp IS A POINTER WITH *
    std::cout << "SetWeapon() to " << wp->getType() << ".\n";
}

void HumanB::attack()
{
    if (wp == NULL)
        std::cout << name << " does not have any weapon.\n";
    else
        std::cout << name << " attacks with their " << wp->getType() << ".\n";
}
