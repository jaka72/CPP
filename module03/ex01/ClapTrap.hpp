/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 13:54:04 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include "colors.h"

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_pts;
		int			_energy_pts;
		int			_attack_damage;

	public:
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		
	// Destructor	
		~ClapTrap();
		
	// Overloaded operators
		ClapTrap &operator= (const ClapTrap &claptrap);

	// Public member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
