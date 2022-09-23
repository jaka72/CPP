/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 11:49:02 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:15:48 by jaka          ########   odam.nl         */
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
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);

	// Deconstructors
		virtual ~ScavTrap();

	// Overloaded Operators
		ScavTrap &operator=(const ScavTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void guardGate(void);
	// Getter

	// Setter

};
