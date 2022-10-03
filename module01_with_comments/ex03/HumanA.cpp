/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 14:07:41 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

// Constructor
// With "Initialisation List" ==>  COLON : after brackets()
HumanA::HumanA(std::string name, Weapon &weapon)
							  : _weapon(weapon)
{
		_name   = name;
//		_weapon = weapon;		// MUST BE IN THE 'Init. List'
}


// Destructor
HumanA::~HumanA()
{
	//std::cout << "Called Destructor.\n";
}


// Member function
void	HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weapon.getType() << " ... \n";
}
