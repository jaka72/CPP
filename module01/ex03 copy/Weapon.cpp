/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:13:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:32:43 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Constructor
Weapon::Weapon(const std::string tp)
{
	type = tp;			// WHICH VARIANT TO USE ??
	// setType(tp);
}


// Destructor
Weapon::~Weapon()   	// DESTRUCTOR
{   }


void Weapon::setType(const std::string &type_orig)
{
	type = type_orig;
}



// IF A CONST REFERENCE IS RETURNS, THAT MEANS
// THAT THIS VARIABLE CANT BE CHANGED LATER OUTSIDE.
// SO WHY THIS FUNCTION CANT BE gettype() const  ???
const std::string& Weapon::getType()
{
	std::string &typeREF = type; 
	return typeREF;
}
