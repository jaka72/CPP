/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:34 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/06 16:23:24 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string  _name;
		Weapon      *_weapon;
//		Weapon      &_weapon;		// A reference must be initialized in the constructors :init.list
									// But a pointer can wait for later, to be assigned to some variable

	public:

		// Parameterized constructor
		HumanB(std::string name);

		// Destructor
		~HumanB();

		// Member function
		void    setWeapon(Weapon &weapon);	// COULD BE BOTH * OR &   ,BUT THE SUBJECT
//		void    setWeapon(Weapon *weapon);	//		WANTS jim.setWeapon(hammer)  
											//		NOT  (&hammer)

		void    attack();
};

#endif
