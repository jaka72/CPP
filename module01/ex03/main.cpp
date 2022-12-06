/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:14 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/06 16:24:32 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("plastic yellow club");
		bob.attack();
	}
	std::cout << "\n";
	
	{
		Weapon hammer = Weapon("big steel hammer");

		HumanB jim("Jim");
		jim.attack();

		jim.setWeapon(hammer);	// IN SUBJECT: WITHOUT ADDRESS
//		jim.setWeapon(&hammer);
		
		jim.attack();
		hammer.setType("little red hammer");
		jim.attack();
	}
	return 0;
}
