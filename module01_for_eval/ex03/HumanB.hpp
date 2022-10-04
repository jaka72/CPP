/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:34 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 12:12:47 by jmurovec      ########   odam.nl         */
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
