/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 18:32:48 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 18:32:49 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
// #include <iostream>

Zombie  *newZombie(std::string name)
{
	// Zombie *zb;
	// zb = new Zombie(name);
	// return (zb);
	return (new Zombie(name));
}
