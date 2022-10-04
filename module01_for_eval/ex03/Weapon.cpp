/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:13:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 12:05:37 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &type)
{
	_type = type;
	// setType(type);
}


// Destructor
Weapon::~Weapon()
{	}


// Setter
void Weapon::setType(const std::string &type)
{
	_type = type;
	std::cout << "   setType() to " << _type << ".\n\n";
}


// Getter
const std::string& Weapon::getType()
{
	const std::string& typeREF = _type;
	return typeREF;
}
