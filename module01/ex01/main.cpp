/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:00:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Keyword "new" allocated memory for the array on the HEAP. 
//	So it is dinamic.

int	main(void)
{
	int n = 3;
	
	Zombie	*horde;	// HERE NOT YET horde[3]   BUT IT WILL BE INSIDE THE
					//	FUNCTION zombieHorde
					// THIS IS JUST A POINTER OF THE FIRST, DOES NOT MATTER 
					// IF THERE ARE MORE ELEMENTS AFTER IT

	// horde = new Zombie;

	//std::cout << "get name: " << horde.get_name() << "\n";

	horde = zombieHorde(n, "Silvia");

	delete[] horde;

	return (0);
}
