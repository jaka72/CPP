/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 19:36:56 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/11 15:16:03 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"
// #include "ScavTrap.hpp"

class FragTrap: public ClapTrap // , public ScavTrap
{
	private:						// IN THE BASE CLASS OF THIS CLASS, 
									//	IT MUST HAVE protected: NOT private;   !!!
		// std::string	m_name;		// Derived class already inherits 
		// int			hit_pts;	// these members from the base class
		// int			energy_pts;
		// int			attack_damage;
		// int	guard;
		
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

// FragTrap::FragTrap()
// { }

// FragTrap::FragTrap(std::string name)
// {
// 	m_name = name;
// 	hit_pts = 10;
// 	energy_pts = 10;
// 	attack_damage = 0;
// };




#endif
