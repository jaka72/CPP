/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:11:50 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int n = 3;
	
	Zombie	*horde;
	horde = zombieHorde(n, "Silvia");

	int i = 0;
	while (i < n)
	{
		horde[i].announce();
		i++;
	}

	delete[] horde;

	return (0);
}
