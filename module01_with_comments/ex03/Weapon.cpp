/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:13:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:39:24 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string &type)
{
	_type = type;			// WHICH VARIANT TO USE ??
	// setType(tp);
}


// Destructor
Weapon::~Weapon()
{	}


void Weapon::setType(const std::string &type)
{
	_type = type;
}


// IF A CONST REFERENCE RETURNS, THAT MEANS
// THAT THIS VARIABLE CANT BE CHANGED LATER OUTSIDE.
// SO WHY THIS FUNCTION CANT BE gettype() const  ???
const std::string& Weapon::getType()
{
	const std::string& typeREF = _type;
	return typeREF;
}
