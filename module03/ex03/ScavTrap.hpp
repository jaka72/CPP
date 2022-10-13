/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 14:52:44 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
		int	_guard;
		
	public:
		// Constructors
		ScavTrap();
		
		// Parameterized constructors
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap();

		// Overloaded operators
		ScavTrap &operator= (const ScavTrap &scavtrap);

		// Public member functions
		void guardGate();
		void print_hit_pts();	// just for testing
		void attack(const std::string &target);

		// Getters
		int get_energy_points();


};

// ScavTrap::ScavTrap()
// { }

// ScavTrap::ScavTrap(std::string name)
// {
// 	m_name = name;
// 	hit_pts = 10;
// 	energy_pts = 10;
// 	attack_damage = 0;
// };




#endif
