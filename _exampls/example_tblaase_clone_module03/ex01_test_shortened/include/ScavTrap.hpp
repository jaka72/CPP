/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:49:02 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:33:51 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include "ClapTrap.hpp"

// classes

class ScavTrap: public ClapTrap
{
	private:
		bool _guarding_gate;
	public:
	// Constructors
		ScavTrap();

	// Deconstructors
		virtual ~ScavTrap();

};
