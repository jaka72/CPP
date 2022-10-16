/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   DiamondTrap.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/14 13:30:21 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

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
		//virtual ~DiamondTrap();
		~DiamondTrap();

		// Public member functions
		void attack(const std::string &name);
		void WhoAmI();

		
		// Getter
		void print_values();
};

#endif
