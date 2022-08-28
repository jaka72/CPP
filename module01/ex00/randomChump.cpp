#include "Zombie.hpp"
// #include <iostream>

// void	Zombie::announce(void) // URGENTLY CLASS BEFORE FUNCTION NAME !!!
// {
// 	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
// }


void	randomChump(std::string name)
{
	Zombie	*zb;
	zb = newZombie(name);
	zb->announce();
	delete zb;
}
