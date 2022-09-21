/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:33:00 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(std::string name_public)
		{
			name = name_public;
		}
		~Zombie(void)
		{
			std::cout << name << " destroyed.\n";
		}
		void	announce(void);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif