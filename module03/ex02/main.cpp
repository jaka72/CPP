/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 14:21:23 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
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


int main()
{
	std::cout << "\n--- TEST: MAKE OBJECTS ------------------------------- \n\n";

	ClapTrap marko("Marko");
	ScavTrap boris("Boris");
	FragTrap donald("Donald");
	FragTrap donald2;
	donald2 = donald;


	std::cout << "\n\n--- TEST: ATTACK AND BE REPAIRED ---------------------- \n\n";

	marko.attack("Boris");
	boris.takeDamage(0);
	boris.beRepaired(3);

	boris.attack("Marko");
	marko.takeDamage(20);
	marko.beRepaired(3);

	donald.attack("Boris");
	boris.takeDamage(5);
	boris.beRepaired(1);
	
	
	std::cout << "\n\n--- TEST: TAKE BIG DAMAGE AND DIE -------------------- \n\n";
	donald.takeDamage(100);
	donald.attack("Marko");

	
	std::cout << "\n\n--- TEST: guadGate() FUNCTION ------------------------- \n";

	boris.guardGate();
	boris.guardGate();

	std::cout << "\n\n--- TEST: highFivesGuys() FUNCTION -------------------- \n";

	donald.highFivesGuys();


	std::cout << "\n\n--- TEST: SPEND ALL ENERGY POINTS BY ATTACKING --------- \n\n";
	FragTrap mario("Mario");
	int i = 0;
	while (i < 101)
	{
		//mario.attack("Silvio");
		i++;
	}


	std::cout << "\n\n--- DESTRUCTING ALL ----------------------------------- \n\n";

	return (0);
}
