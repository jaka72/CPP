/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:55 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 13:51:42 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
	INSTRUCTIONS:
	Each player loses x hit points when attacked (hitpoints == health)
				gains x hit points when repaired.
				loses 1 energy point when attacks.
				loses 1 energy point when repaired.

	It is not possible to get energy points back.
	When one has 0 hit/energy points, it's game over.
*/


int main()
{
	std::cout << "\n--- TEST: MAKE OBJECTS ------------------------------- \n\n";

	ClapTrap marko("Marko");

	ClapTrap marko2(marko);	// copy constr.
	ClapTrap marko3;		// default constr.
	marko3 = marko;			// overload=
	
	ScavTrap boris("Boris");


	std::cout << "\n\n--- TEST: ATTACK AND BE REPAIRED ---------------------- \n\n";

	marko.attack("Boris");
	boris.takeDamage(0);

	boris.attack("Marko");
	marko.takeDamage(20);
	marko.beRepaired(3);


	ScavTrap silvio("Silvio");
	silvio.attack("Boris");
	boris.takeDamage(20);
	
	boris.beRepaired(1);
	silvio.beRepaired(1);


	std::cout << "\n\n--- TEST: TAKE BIG DAMAGE AND DIE ---------------------- \n\n";
	boris.takeDamage(100);
	boris.attack("Silvio");


	std::cout << "\n\n--- TEST: guadGate() FUNCTION -------------------------- \n\n";

	boris.guardGate();
	boris.guardGate();


	std::cout << "\n\n--- TEST: SPEND ALL ENERGY POINTS BY ATTACKING --------- \n\n";

	int i = 0;
	while (i < 101)
	{
		//silvio.attack("Silvio");
		i++;
	}

	std::cout << "\n\n--- DESTRUCTING ALL ---------------------------------- \n\n";

	return (0);
}
