/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:06:40 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:19:58 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <sstream> //std::stringstream

class Zombie
{
	public:
		// IN THIS CASE THERE IS NO CONSTRUCTOR, BUT
		//		THERE IS A SEPARATE FUNCTION THAT WILL
		//		GIVE NAME TO EACH OF THE NEW INSTANCES
		// Zombie(std::string name_orig)
		// {
		// 	name_private = name_orig;
		// }

		~Zombie(void);

		void announce(void);
		void setname_orig(std::string name_orig);

	private:
	// zombie 이름
		std::string name_private;
};

Zombie* zombieHorde( int N, std::string name );

#endif
