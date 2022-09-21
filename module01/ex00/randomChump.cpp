/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:32:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <iostream>

// void	Zombie::announce(void) // URGENTLY CLASS BEFORE FUNCTION NAME !!!
// {
// 	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
// }


void	randomChump(std::string name)
{
	Zombie	*zb;
	zb = newZombie(name);
	zb->announce();
	delete zb;
}
