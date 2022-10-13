/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 18:39:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/11 16:13:35 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include "colors.h"

/*
	It is best practice to initialize the members immediately
			ie:	int hitpoints{20}
				ClapTrap = default;
	But it is only allowed from c++11
*/
class ClapTrap
{
	// private:		//	IF THIS IS THE BASE CLASS FOR AN INHERITED CLASS
	protected:		// 		THEN IT MUST BE protected, OR IT GIVES ERROR ????
		std::string	_name;
		int			_attack_damage;
		bool		_guard;

	public:
		int			_hit_pts;
		int			_energy_pts;
	// Constructors:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		
	// Destructor	
		virtual ~ClapTrap();	// WHY SHOULD HERE BE VIRTUAL ???
		// ~ClapTrap();	// WHY SHOULD HERE BE VIRTUAL ???
		
	// Overloaded operators
		ClapTrap &operator= (const ClapTrap &claptrap);

	// Public member functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void print__hit_pts();	// just for testing

};

#endif
