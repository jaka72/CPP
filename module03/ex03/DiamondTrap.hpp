/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 12:25:41 by jaka          ########   odam.nl         */
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
		

		
	public:
		// Constructors
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);

		// Overloaded operators
		DiamondTrap &operator= (const DiamondTrap &orig);
		
		// Destructor
		~DiamondTrap();

		// Public member functions
		void highFivesGuys(void);
		//void takeDamage(unsigned int amount);
		//void guardGate();
		//void print_hit_pts();	// just for testing

};




#endif
