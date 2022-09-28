/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:01:14 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// try with default construcitr
Zombie::Zombie()
{
    std::cout << "Default construtor\n";
    
    name = "default name";
}


// try with parameterized construcitr
Zombie::Zombie(std::string nm)
{
    std::cout << "Parameterized\n";
    name = nm;
}

void    Zombie::set_name(std::string name_public)
{
    name = name_public;
}


// GETTER, CAN BE DELETED, NOT NECESSARY
std::string    Zombie::get_name()
{
    return name;
}


void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}


Zombie::~Zombie(void)
{
    std::cout << name << " destroyed.\n";
}
