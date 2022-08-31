#include "Zombie.hpp"

// void    Zombie::set_name(std::string name_public)
// {
//     name = name_public;
// }

// Zombie::Zombie()
// { }

// Zombie::Zombie(std::string name_public)
// {
//     name = name_public;
// }

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}


Zombie::~Zombie(void)
{
    std::cout << name << " destroyed.\n";
}
