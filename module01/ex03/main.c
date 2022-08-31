#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        //std::cout << "From main: " << club.getType() << " end/ \n";

        //const std::string aaa = club.getType();
        //std::string aaa = club.getType();
        //std::cout << "aaa: " << aaa << '\n'; 
        //aaa = "aaaaaaaaa";

        //std::cout << "New aaa: " << aaa << '\n'; 
        //std::cout << "club.type: " << club.type << '\n'; // CANNOT PRINT, BECASE ITS DECLARED PRIVATE 

        HumanA bob("bob", club);
        bob.attack();
        club.setType("plastic yellow club");
        //std::cout << "Changed type " << club.getType() << "... \n";
        bob.attack();
    }
    {
        Weapon hammer = Weapon("big steel hammer");

        HumanB jim("Jim");
        jim.setWeapon(hammer);
        jim.attack();


    }

    //
    //
    //

    return 0;
}