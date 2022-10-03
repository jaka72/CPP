/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 14:51:05 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

// Parameterized constructor
HumanB::HumanB(std::string name) // : _name(name), _weapon(NULL)
{
	_name = name;
	_weapon = NULL;			// *_wp IS A POINTER (private member)
}


// Destructor
HumanB::~HumanB()
{	}



void HumanB::setWeapon(Weapon& weapon)
{
	
	_weapon = &weapon;  // MUST BE WITH & ADRES, BECAUSE private _wp IS A POINTER WITH *
	
	std::cout << "   SetWeapon() to " << _weapon->getType() << ".\n\n";
}


void HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << _name << " does not have a weapon yet.\n";
	else
		std::cout << _name << " attacks with his " << _weapon->getType() << ".\n";
}
