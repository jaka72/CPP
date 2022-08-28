#include "Zombie.hpp"
// #include <iostream>

Zombie  *newZombie(std::string name)
{
	// Zombie *zb;
	// zb = new Zombie(name);
	// return (zb);
	return (new Zombie(name));
}
