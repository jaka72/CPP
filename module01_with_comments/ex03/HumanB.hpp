/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:34 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 14:22:07 by jaka          ########   odam.nl         */
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
		Weapon      *_weapon;	// MUST BE A POINTER, BECAUSE IF & REFERECE,
//		Weapon      &_weapon;	// 
							//  THEN IT MUST BE INITIALIZED ON THE SPOT,
							//  (at the moment of construction)
							//	BUT IN CONSTRUCTION THERE IS NO WEAPON IN THE ARGS,
							// 	SO WEAPON IS EMPTY UNTIL MUCH LATER,
							// 	WHEN setWeapon() WILL BE CALLED

	public:
		HumanB(std::string name);

		~HumanB();

		void    setWeapon(Weapon &weapon);	// COULD BE BOTH * OR &   ,BUT THE SUBJECT
//		void    setWeapon(Weapon *weapon);	//		WANTS jim.setWeapon(hammer)  
											//		NOT  (&hammer)

		void    attack();
};

#endif