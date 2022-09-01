#include <iostream>
#include "HumanA.hpp"

// THIS IS "Initialisation List"
//      COLON : AFTER CLASS()
//      NOW NO NEED TO WRITE ASSIGNMENTS IN THE BODY, 
//          LIKE  name = name_orig  (NOT PREFFERED)
HumanA::HumanA(std::string name_orig, Weapon &wp_orig) : name(name_orig), wp(wp_orig)
{
    // BODY CAN STAY EMPTY

    //name = name_orig;
    //wp = wp_orig;
}

HumanA::~HumanA()
{
    //std::cout << "Called Destructor.\n";
}

void	HumanA::attack()
{
    std::cout << name << " attacks with their " << wp.getType() << " ... \n"; 
}
