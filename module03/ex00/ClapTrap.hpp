/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 13:46:02 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/08 13:48:59 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>


/*
	It is best practice to initialize the members immediately
			ie:	int hitpoints{20}
				ClapTrap = default;
	But it is only allowed from c++11
*/
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
