/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:10:46 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie()
{
	std::cout << "Default construtor\n";
	_name = "default name";
}


// Parameterized constructor
Zombie::Zombie(std::string name)
{
	std::cout << "Parameterized\n";
	_name = name;
}

// Setter
void    Zombie::set_name(std::string name)
{
	_name = name;
}


// Member functions
void    Zombie::announce()
{
	std::cout << "   " << _name << " says: BraiiiiiiinnnzzzZ\n";
}


// Destructor
Zombie::~Zombie(void)
{
	std::cout << _name << " destroyed.\n";
}
