/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:34 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 15:26:44 by jaka          ########   odam.nl         */
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
		Weapon      *_wp;	// MUST BE A POINTER, BECAUSE IF & REFERECE,
//		Weapon      &_wp;	// 
							//  THEN IT MUST BE INITIALIZED ON THE SPOT,
							//  (at the moment of construction)
							//	BUT AT AT CONSTRUCTION THERE IS NO WEAPON IN THE ARGS,
							// 	SO WEAPON IS EMPTY UNTIL MUCH LATER,
							// 	WHEN setWeapon() WILL BE CALLED

	public:
		HumanB(std::string name);

		~HumanB();

		void    setWeapon(Weapon &wp);	// COULD BE BOTH * OR &   ,BUT THE SUBJECT
//		void    setWeapon(Weapon *wp);	//		WANTS jim.setWeapon(hammer)  
										//			NOT  (&hammer)

		void    attack();
};

#endif