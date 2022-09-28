/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:14 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:33:37 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	In constructor, which variant to use?
		type = tp;
		// setType(tp);
			AND
		Weapon::Weapon(const std::string &tp)   ----> with & or without & ???
		


*/


int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("plastic yellow club");
		bob.attack();
	}
	{
		Weapon hammer = Weapon("big steel hammer");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(hammer);
		jim.attack();
		hammer.setType("little hammer from Utrecht");
		jim.attack();
	}

	return 0;
}