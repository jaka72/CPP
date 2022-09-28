/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:34 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:06:35 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon      *wp;	// MUST BE A POINTER, BECAUSE IF & REFERECE,
							//  THEN IT MUST BE INITIALIZED HERE ON THE SPOT,
							//	BUT AT THIS POINT THE WEAPON IS EMPTY,
							// 	BECAUSE setWeapon() IS NOT CALLED YET

	public:
		HumanB(std::string name);

		~HumanB();

		void    setWeapon(Weapon &wp_orig);

		void    attack();
};

#endif