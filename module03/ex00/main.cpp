#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

/*
	INSTRUCTIONS:
		Each player loses xy hit points when attacked (hitpoints == health)
					loses 1 energy point when attacks.
					loses 1 energy point when repaired.
					gains xy hit points when repaired.

	It is not possible to get energy points back.
	When one has 0 hit/energy points, it's game over.

	After attack(), probably victim should call takeDamage()


*/

/*
	QUESTIONS:
	- What is the logic of order of constr. and destr.?? 
	- Why exactly is destruction in reverse mode? 
*/

int main()
{
	ClapTrap marko("Marko");
	// ClapTrap silvio("Silvio");

	// marko.attack("Silvio");
	// silvio.takeDamage(7);
	// silvio.beRepaired(3);
	// silvio.takeDamage(7);

	// int i{0};
	// while (i < 10)
	// {
	// 	marko.attack("Silvio");
	// 	i++;
	// }

	return (0);
}
