/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:41 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/17 15:52:51 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:						// IN THE BASE CLASS (parent) OF THIS CLASS, 
									//	IT MUST HAVE protected: NOT private;   !!!
		// std::string	_name;		// Derived class already inherits 
		// int			_hit_pts;	// these members from the base class
		// int			_energy_pts;
		// int			_attack_damage;
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
		void print__hit_pts();	// just for testing

};

// ScavTrap::ScavTrap()
// { }

// ScavTrap::ScavTrap(std::string name)
// {
// 	_name = name;
// 	_hit_pts = 10;
// 	_energy_pts = 10;
// 	_attack_damage = 0;
// };




#endif
