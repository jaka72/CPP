/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:55 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 11:33:18 by jaka          ########   odam.nl         */
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
	ClapTrap marko("Marko");

	// ClapTrap luka(marko);
	// luka.attack("Marko");
	// ClapTrap b;
	// b = luka;
	// b.attack("xxxx");
	
	ScavTrap boris("Boris");

	marko.attack("Boris");
	boris.takeDamage(0);

	boris.attack("Marko");
	marko.takeDamage(20);
	marko.beRepaired(3);


	// ScavTrap silvio("Silvio");

	// silvio.attack("Boris");
	// boris.takeDamage(20);
	
	// boris.beRepaired(1);
	// silvio.beRepaired(1);

	// boris.guardGate();
	// boris.guardGate();


	return (0);
}
