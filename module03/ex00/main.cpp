/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:45:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/08 19:58:30 by jaka          ########   odam.nl         */
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

	After attack(), probably victim should call takeDamage()
*/


/*
	QUESTIONS:
	Is he allowed to have more hit points that initial value? Probably yes

	Copy contructor copies the address, so it actually points to the same object,
	it is not just a separate copy?
	WHat if I want to make a separate independant copy??
*/

int main()
{
	ClapTrap marko("Marko");
	ClapTrap silvio("Silvio");

	marko.attack("Silvio");
	silvio.takeDamage(0);

	silvio.attack("Marko");	
	marko.takeDamage(0);



	//silvio.beRepaired(1);
	//marko.beRepaired(1);
	
	
	std::cout << "--- Test: loose all points ---------------- \n\n";

	int i = 0;
	while (i < 10)
	{
		marko.attack("Silvio");
		i++;
	}

	
	return (0);
}
