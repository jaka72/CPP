/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 12:56:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (std::string name)
{
	_name = name;
	std::cout << "Constructor (" << _name << ") \n";
}


void	Zombie::announce(void)
{
	std::cout << "   " << _name << " says: BraiiiiiiinnnzzzZ...\n";
}


Zombie::~Zombie()
{
	std::cout << _name << " destroyed.\n\n";
}
