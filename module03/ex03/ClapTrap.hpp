/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/12 14:39:17 by jmurovec      ########   odam.nl         */
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
		bool		_guard;

	public:
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		
	// Destructor	
		//virtual ~ClapTrap();	
		~ClapTrap();
		
	// Overloaded operators
		ClapTrap &operator= (const ClapTrap &claptrap);

	// Public member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
