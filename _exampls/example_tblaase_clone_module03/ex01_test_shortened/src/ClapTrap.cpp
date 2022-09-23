/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 10:33:50 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:33:29 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "../include/ClapTrap.hpp"


// Constructors
ClapTrap::ClapTrap(): _hit_pts(10)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}


// Deconstructors
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Deconstructor for \n";
}
