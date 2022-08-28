#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i {0};
//	Zombie *zb[N];		// MAYBE NOT GOOD
	Zombie	*horde;
	horde = new Zombie[N];	// THIS AUTOMATICALLY CALLES THE DESTRUCTOR 5 TIMES

	while (i < N)
	{
		//zb[i] = new Zombie;
		//zb[i] = new Zombie(name);
		// std::cout << i << " print name: " << zb[i]->get_name << "\n";
		
		horde[i].set_name(name);
		
		//std::cout << i << " " << horde[i].get_name() << "\n";
		i++;
	}

	// return zb[0];
	return (horde);
}

int	main(void)
{
	int n {3};
	Zombie	*horde;	// HERE NOT YET horde[3]   BUT INSIDE FUNCTION zombieHorde
					// THIS IS JUST A POINTER OF THE FIRST, DOES NOT MATTER IF THERE ARE MORE AFTER IT

	horde = zombieHorde(n, "Danny");
	delete[] horde;

	return (0);
}
