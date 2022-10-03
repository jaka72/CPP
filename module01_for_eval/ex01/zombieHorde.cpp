/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:08:52 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	horde = new Zombie[N];	// AUTOMATICALLY CALLS THE Default CONSTRUCTOR N TIMES

	int i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}

	return (horde);
}
