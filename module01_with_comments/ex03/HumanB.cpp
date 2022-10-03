/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 14:21:26 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

// Parameterized constructor
HumanB::HumanB(std::string name) // : _name(name) //, _weapon(NULL)
{
	_name = name;
	_weapon = NULL;			// *_wp IS A POINTER (private member)
							// IF _wp WAS A REFERENCE, IT WOULD
							// HAVE TO BE INITIALIZED HERE IN CONSTR,
							// BUT THIS IS IMPOSSIBLE, BECAUSE
							// THERE IS NO Weapon INSIDE HERE 
}


// Destructor
HumanB::~HumanB()
{	}



// TWO MEANINGS OF THE &
//		(Weapon& wp)	---> passed as a reference
//		_wp = &wp		---> give address of wp to pointer _wp
// EVEN IF THE &wp IN THE ARGS IS A REFERENCE, IT STILL MUST BE GIVEN
// TO THE _wp AS AN ADRES, BECAUSE _wp IS A POINTER * (private member) 
// void HumanB::setWeapon(Weapon *wp)
void HumanB::setWeapon(Weapon& weapon)
{
	
	_weapon = &weapon;  // MUST BE WITH & ADRES, BECAUSE private _wp IS A POINTER WITH *
	
	std::cout << "SetWeapon() to " << _weapon->getType() << ".\n";
}


void HumanB::attack()
{
	if (_weapon == NULL)
		std::cout << _name << " does not have a weapon yet.\n";
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << ".\n";
}
