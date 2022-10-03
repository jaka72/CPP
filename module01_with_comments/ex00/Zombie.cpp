/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 11:46:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name_public)
{
	name = name_public;
	std::cout << "Constructor (" << name << ") \n";
}


void	Zombie::announce(void) // URGENTLY CLASS BEFORE FUNCTION NAME !!!
{
	std::cout << "   " << name << " says: BraiiiiiiinnnzzzZ...\n";
}


Zombie::~Zombie()
{
	std::cout << name << " destroyed.\n";
}
