/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:40:51 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

// THIS IS "Initialisation List"
//      COLON : AFTER CLASS()
//      NOW NO NEED TO WRITE ASSIGNMENTS IN THE BODY, 
//          LIKE  name = name_orig  (NOT PREFFERED)
HumanA::HumanA(std::string name_orig, Weapon &wp_orig)
					: _name(name_orig), _wp(wp_orig)
{
	// BODY CAN STAY EMPTY
	//	name = name_orig;
	//	wp = wp_orig;
}


HumanA::~HumanA()
{
	//std::cout << "Called Destructor.\n";
}


void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _wp.getType() << " ... \n"; 
}
