#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("plastic yellow club");
        bob.attack();
    }
    {
        Weapon hammer = Weapon("big steel hammer");

        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(hammer);
        jim.attack();
        hammer.setType("little hammer from Utrecht");
        jim.attack();

    }

    return 0;
}