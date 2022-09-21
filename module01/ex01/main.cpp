/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:33:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Keyword "new" allocated memory for the array on the HEAP. So it is dinamic.
// Not sure if we are allowed to use malloc()

int	main(void)
{
	int n = 3;
	
	Zombie	*horde;	// HERE NOT YET horde[3]   BUT IT WILL BE INSIDE FUNCTION zombieHorde
					// THIS IS JUST A POINTER OF THE FIRST, DOES NOT MATTER 
					// IF THERE ARE MORE ELEMENTS AFTER IT

	horde = zombieHorde(n, "Silvia");
	delete[] horde;

	return (0);
}
