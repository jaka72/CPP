/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:51:59 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 19:52:07 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string name_private;
	
	public:
		void announce(void);

		// IS THIS THE CONSTRUCTOR, CALLED AUTOMATICALLY ???
		Zombie(std::string name_orig)
		{
			name_private = name_orig;
			std::cout << "Constructor2 is called\n";
		}

		// THIS IS THE DESTRUCTOR:
		~Zombie(void)
		{
			//std::cout << "[" << name_orig << "] " << "die." << std::endl;
			std::cout << "[" << name_private << "] " << "die." << std::endl;
		}

	
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif