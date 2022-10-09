/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 11:33:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		int	_guard;
		
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		
		// Destructor
		~ScavTrap();

		// Overloaded operators
		ScavTrap &operator= (const ScavTrap &scavtrap);

		// Public member functions
		//void takeDamage(unsigned int amount);
		void guardGate();
		// void print__hit_pts();	// just for testing

};

#endif
