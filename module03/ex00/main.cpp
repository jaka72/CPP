/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:45:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 13:16:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
	INSTRUCTIONS:
	Each player loses x hit points when attacked (hitpoints == health)
				gains x hit points when repaired.
				loses 1 energy point when attacks (energy points)
				loses 1 energy point when repaired.

	It is not possible to get energy points back.
	When one has 0 hit/energy points, it's game over.
*/

int main()
{
	std::cout << "\n--- TEST: MAKE OBJECTS ------------------------------- \n\n";
	
	ClapTrap marko("Marko");
	ClapTrap silvio("Silvio");

	ClapTrap marko2(marko);	// copy constr + overload=
	ClapTrap marko3;		// default constr.
	marko3 = marko;			// overload=



	std::cout << "\n\n--- TEST: ATTACK AND BE REPAIRED ---------------------- \n\n";

	marko.attack("Silvio");
	silvio.takeDamage(0);

	silvio.attack("Marko");	
	marko.takeDamage(0);


	silvio.beRepaired(1);
	marko.beRepaired(1);
	
	
	std::cout << "\n\n--- TEST: TAKE BIG DAMAGE AND DIE ---------------------- \n\n";
	
	silvio.takeDamage(100);
	silvio.attack("Marko");


	std::cout << "\n\n--- TEST: SPEND ALL ENERGY POINTS BY ATTACKING --------- \n\n";

	int i = 0;
	while (i < 101)
	{
		//marko.attack("Silvio");
		i++;
	}


	std::cout << "\n\n--- DESTRUCTING ALL ----------------------------- \n\n";
	return (0);
}
