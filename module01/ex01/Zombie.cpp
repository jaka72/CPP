/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:42 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:33:43 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
