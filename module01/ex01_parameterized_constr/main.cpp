#include "Zombie.hpp"

int	main(void)
{
	int n {3};
	Zombie	*horde;	// HERE NOT YET horde[3]   BUT IT WILL BE INSIDE FUNCTION zombieHorde
					// THIS IS JUST A POINTER OF THE FIRST, DOES NOT MATTER 
					// IF THERE ARE MORE ELEMENTS AFTER IT

	horde = zombieHorde(n, "Silvia");
	delete[] horde;

	return (0);
}
