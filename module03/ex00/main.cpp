#include "ClapTrap.hpp"


int main()
{
	ClapTrap marko("Marko");
	ClapTrap silvio("Silvio");

	marko.attack("Silvio");
	silvio.takeDamage(7);
	silvio.beRepaired(3);
	silvio.takeDamage(7);

	int i{0};
	while (i < 10)
	{
		marko.attack("Silvio");
		i++;
	}

	return (0);
}
