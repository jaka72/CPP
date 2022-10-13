/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:46:02 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/12 10:05:24 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hit_pts;
		int			_energy_pts;
		int			_attack_damage;

	public:
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &claptrap);
		
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
