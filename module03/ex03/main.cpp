/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:00 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/14 13:28:56 by jaka          ########   odam.nl         */
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
*/


int main()
{
	std::cout << "\n--- TEST: MAKE OBJECTS ------------------------------- \n\n";
	
	//ClapTrap marko("Marko");
	// ClapTrap silvio("Silvio");

	//ClapTrap marko2(marko);	// copy constr + overload=
	//ClapTrap marko3;		// default constr.
	//marko3 = marko;			// overload=



	// std::cout << "\n\n--- TEST: ATTACK AND BE REPAIRED ---------------------- \n\n";

	// marko.attack("Silvio");
	// silvio.takeDamage(0);

	// silvio.attack("Marko");	
	// marko.takeDamage(0);


	// silvio.beRepaired(1);
	// marko.beRepaired(1);
	
	
	// std::cout << "\n\n--- TEST: TAKE BIG DAMAGE AND DIE ---------------------- \n\n";
	
	// silvio.takeDamage(100);
	// silvio.attack("Marko");


	// std::cout << "\n\n--- TEST: SPEND ALL ENERGY POINTS BY ATTACKING --------- \n\n";

	// int i = 0;
	// while (i < 10)
	// {
	// 	//marko.attack("Silvio");
	// 	i++;
	// }


	std::cout << "\n\n--- TEST: DIAMONDTRAP VALUES ------------------- \n\n";

	//DiamondTrap d1;
	// DiamondTrap diamond("Diamond");
	// diamond.print_values();
	
	
	// std::cout << "\n\n--- TEST: DiamondTrap.attack() ------------------ \n\n";
	
	// diamond.attack("mister X");



	// std::cout << "\n\n--- TEST: WhoAmI() ------------------------------ \n\n";

	// diamond.WhoAmI();



	//std::cout << "\n\n--- DESTRUCTING ALL ----------------------------- \n\n";




	// jaka ////////////////////////
	//ClapTrap c1("ccc1");

	//FragTrap fff("fff");
	//ScavTrap sss("sss1");

	DiamondTrap d1;

	d1.print_values();

	std::cout << "temp: " << d1.temp << "\n";

	return (0);
}
