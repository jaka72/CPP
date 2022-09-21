/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:33:55 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie	*horde;
	horde = new Zombie[N];	// THIS AUTOMATICALLY CALLS THE DESTRUCTOR 5 TIMES

	while (i < N)
	{
		//zb[i] = new Zombie;
		//zb[i] = new Zombie(name);
		// std::cout << i << " print name: " << zb[i]->get_name << "\n";
		
		horde[i].set_name(name);
        horde[i].announce();
		
		//std::cout << i << " " << horde[i].get_name() << "\n";
		i++;
	}

	// return zb[0];
	return (horde);
}
