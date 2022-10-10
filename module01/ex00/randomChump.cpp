/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:52 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/25 17:35:47 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


void	randomChump(std::string name)
{
	//Zombie *zb = new Zombie(name); 

	Zombie	*zb = newZombie(name);
	zb->announce();
	
	delete zb;
}
