/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 11:23:19 by tblaase       #+#    #+#                 */
/*   Updated: 2022/10/14 13:05:11 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// classes

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
	// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);

	// Deconstructors
		virtual ~DiamondTrap();

	// Overloaded Operators
		DiamondTrap &operator=(const DiamondTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void whoAmI(void);
	// Getter

	// Setter


	// jaka //////////////////
	void print_values();

};