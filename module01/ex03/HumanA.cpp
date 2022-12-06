/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/06 16:12:41 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

// Constructor, with "Initialisation List"
HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) // _weapon = weapon
{
	_name = name;
//	_weapon(weapon);  // error, no call operator
//	_weapon = weapon; // error, no default constr /or/ no initializer
}


// Destructor
HumanA::~HumanA()
{	}


// Member function
void	HumanA::attack()
{
	std::cout << _name << " attacks with his " << _weapon.getType() << " ... \n";
}
