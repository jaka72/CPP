/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/25 19:16:10 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie	*horde;
	horde = new Zombie[N];	// THIS AUTOMATICALLY CALLS THE Default CONSTRUCTOR 5 TIMES ???
							// IS IT POSSIBLE TO DO THIS VIA PARAMETERIZED CONSTRUCTOR ??
							// 		something like  horde = new Zombie[3]("Johan")

	while (i < N)
	{
		horde[i].set_name(name);
		horde[i].announce();
		i++;
	}

	return (horde);
}
