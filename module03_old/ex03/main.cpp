/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/11 16:18:43 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

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
	// ClapTrap marko("Marko");
	// ScavTrap boris("Boris");
	
	// FragTrap donald("Donald");
	// //ClapTrap silvio("Silvio");

	// marko.attack("Boris");
	// boris.takeDamage(0);

	// boris.attack("Marko");
	// marko.takeDamage(20);

	// marko.beRepaired(3);

	// boris.guardGate();
	// boris.guardGate();

	// donald.highFivesGuys();

	// donald.attack("Joe");
	// donald.takeDamage(5);
	// donald.beRepaired(1);

	DiamondTrap dm;

	std::cout << dm._hit_pts << ",  " << dm._energy_pts << "/n";

	return (0);
}
