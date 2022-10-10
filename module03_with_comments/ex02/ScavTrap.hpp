/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:37:07 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 10:48:15 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:						// IN THE BASE CLASS OF THIS CLASS, 
									//	IT MUST HAVE protected: NOT private;   !!!
	// protected:	// ?????	
		// std::string	m_name;		// Derived class already inherits 
		// int			hit_pts;	// these members from the base class
		// int			energy_pts;
		// int			attack_damage;
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
		void print_hit_pts();	// just for testing

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
