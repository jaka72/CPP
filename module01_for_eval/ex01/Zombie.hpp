/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 13:09:52 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string _name;
	
	public:

		// Default constructor
		Zombie();
		
		// Paremetrized constructor
		Zombie(std::string name);

		// Setter
		void	set_name(std::string name);

		// Member functions
		void	announce();

		// Destructor
		~Zombie();
};

Zombie *zombieHorde(int N, std::string name);

#endif
