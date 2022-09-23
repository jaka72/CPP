/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblaase <tblaase@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 10:33:58 by tblaase       #+#    #+#                 */
/*   Updated: 2022/09/15 15:07:56 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Header-protection
#pragma once

// Includes
#include <string>
#include <iostream>

// classes

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hit_pts;
		unsigned int _energy_pts;
		unsigned int _attack_dmg;

	public:
	// Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);

	// Deconstructors
		virtual ~ClapTrap();

	// Overloaded Operators
		ClapTrap &operator=(const ClapTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	// Getter

	// Setter

};