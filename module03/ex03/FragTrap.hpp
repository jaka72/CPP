/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/09 12:24:44 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include "ClapTrap.hpp"
//# include "ScavTrap.hpp"

class FragTrap: public ClapTrap // , public ScavTrap
{
	private:						// IN THE BASE CLASS OF THIS CLASS, 
									//	IT MUST HAVE protected: NOT private;   !!!
		// std::string	m_name;		// Derived class already inherits 
		// int			hit_pts;	// these members from the base class
		// int			energy_pts;
		// int			attack_damage;
		//int	guard;
		
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
		//void takeDamage(unsigned int amount);
		//void guardGate();
		//void print_hit_pts();	// just for testing

};




#endif
