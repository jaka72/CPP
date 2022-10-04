/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:14 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 12:14:43 by jmurovec      ########   odam.nl         */
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
		

	POINTER VS REFERENCE
	Reference must be initialized at the moment of declaration /or/ construction

	THE ANSWER:
	Human A must have _weapon as a reference, because it gets the Weapon via args,
	so the private variable &_weapon must immediately at construction be initialized
	(which is necessary for the reference).
	So the private _weapon becomes the same address as the arg &weapon.
	It has to be a reference, because it is not enough to just get the values.
	Otherwise it prints nonsense, when printing the getType()
		Also, the weapon has to be in the 'Initialisation List'
		It cannot be initialized in the body of the constructor (but 'name' can be)
		So, if an object Human has a private object of another class (Weapon), and if
		this object is as an arg of the constructor, then it must use the 'Init. List'
		to be initialized.


	
	But Human B does not get the Weapon via args, so its private member *_weapon
	cannot be initialized at the time of construction. So reference cannot be
	used. Better a pointer, because it can wait until later, when setWeapon()
	is called.
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
	std::cout << "\n";
	
	{
		Weapon hammer = Weapon("big steel hammer");

		HumanB jim("Jim");
		jim.attack();

		jim.setWeapon(hammer);	// IN SUBJECT: WITHOUT ADRES
//		jim.setWeapon(&hammer);
		
		jim.attack();
		hammer.setType("little red hammer");
		jim.attack();
	}
	return 0;
}