/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:54 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 11:54:58 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	horde = new Zombie[N];

	int i = 0;
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}

	return (horde);
}
