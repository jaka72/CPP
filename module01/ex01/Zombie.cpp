/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/25 19:06:45 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// try with default construcitr
Zombie::Zombie()
{
    std::cout << "Default construtor\n";
    //name = nm;
}


// try with parameterize d construcitr
Zombie::Zombie(std::string nm)
{
    std::cout << "Parameterized\n";
    name = nm;
}

void    Zombie::set_name(std::string name_public)
{
    name = name_public;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ\n";
}


Zombie::~Zombie(void)
{
    std::cout << name << " destroyed.\n";
}
