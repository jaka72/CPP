/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:33:47 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:33:48 by jaka          ########   odam.nl         */
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

		void    set_name(std::string name);
		void    announce();

		// std::string    get_name()
		// {
		// 	std::cout << name << "\n";
		// 	return name;
		// }

		// Zombie(std::string name)
		// {
		//     name_prive = name;
		// }

		//Zombie()    // CONSTRUCTOR IS NOT NECESSARY APPARENTLY
		//{           // THERE HAS TO BE A SEPARATE FUNCTION TO SET THE NAME
					// FOR EACH ELEMENT. YOU CANNOT AUTOMATICALY GIVE SAME NAME TO
					// EACH ELEMENT OF THE ARRAY (VIA AN ARGUMENT), LIKE IN THE CASE WHEN
					// THERE IS NO ARRAY, BUT ONLY 1 INSTANCE (ex00)
			//std::cout << "Called constructor.\n";
			//get_name("Joco");
			//announce();
		//}

	   ~Zombie(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
