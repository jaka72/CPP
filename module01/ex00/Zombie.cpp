/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 11:53:34 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Parameterized Constructor
Zombie::Zombie (std::string name)
{
	_name = name;
	std::cout << "Constructor (" << _name << ") \n";
}


// Member function
void	Zombie::announce(void)
{
	std::cout << "   " << _name << " says: BraiiiiiiinnnzzzZ...\n";
}


// Destructor
Zombie::~Zombie()
{
	std::cout << _name << " destroyed.\n\n";
}
