/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/12 14:51:16 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"


class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string _name;

		
	public:
		// Constructors
		DiamondTrap();

		
		// Parameterized constructors
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);

		// Overloaded operators
		DiamondTrap &operator= (const DiamondTrap &orig);
		
		// Destructor
		~DiamondTrap();

		// Public member functions
		void attack(const std::string &name);
		void WhoAmI();

		
		// Getter
		void print_values();
};

#endif
