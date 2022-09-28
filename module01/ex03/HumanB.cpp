/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 15:39:51 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)//, _wp(NULL)
{
	//name = name_orig;
	_wp = NULL;				// *_wp IS A POINTER (private member)
							// IF _wp WAS A REFERENCE, IT WOULD
							// HAVE TO BE INITIALIZED HERE IN CONSTR,
							// BUT THIS IS IMPOSSIBLE, BECAUSE
							// THERE IS NO Weapon INSIDE HERE 
}

HumanB::~HumanB()
{	}


// TWO MEANINGS OF THE &
//				(Weapon& wp)	---> reference
//				_wp = &wp		---> address
// EVEN IF THE &wp IN THE ARGS IS A REFERENCE, IT STILL MUST BE GIVEN
// TO THE _wp AS AN ADRES, BECAUSE _wp IS A POINTER * (private member) 
// void HumanB::setWeapon(Weapon *wp)
void HumanB::setWeapon(Weapon& wp)
{
	
	_wp = &wp;  // MUST BE WITH & ADRES, BECAUSE private _wp IS A POINTER WITH *
	
	std::cout << "SetWeapon() to " << _wp->getType() << ".\n";
}


void HumanB::attack()
{
	if (_wp == NULL)
		std::cout << _name << " does not have a weapon yet.\n";
	else
		std::cout << _name << " attacks with their " << _wp->getType() << ".\n";
}
