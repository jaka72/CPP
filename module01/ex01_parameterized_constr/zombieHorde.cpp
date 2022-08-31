#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i {0};
	Zombie	*horde;
	horde = new Zombie[N];	// THIS AUTOMATICALLY CALLS THE DESTRUCTOR N TIMES

	while (i < N)
	{
		//zb[i] = new Zombie;
		//zb[i] = new Zombie(name);
		// std::cout << i << " print name: " << zb[i]->get_name << "\n";
		
		//horde[i].set_name(name);
		horde[i] = Zombie(name);
        horde[i].announce();
		
		//std::cout << i << " " << horde[i].get_name() << "\n";
		i++;
	}

	// return zb[0];
	return (horde);
}
