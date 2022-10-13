/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/13 13:56:33 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	private:
		
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		
		// Destructor
		~FragTrap();

		// Overloaded operators
		FragTrap &operator= (const FragTrap &scavtrap);

		// Public member functions
		void highFivesGuys(void);
		void attack(const std::string &target);
};

#endif
