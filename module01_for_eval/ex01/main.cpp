/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:08 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 11:54:16 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int N = 3;
	
	Zombie	*horde;
	horde = zombieHorde(N, "Silvia");

	int i = 0;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}

	delete[] horde;

	return (0);
}
