/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 12:19:54 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:34:23 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap()
{
	this->_hit_pts = 100;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}



// Deconstructors
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << " called" << std::endl;
}
