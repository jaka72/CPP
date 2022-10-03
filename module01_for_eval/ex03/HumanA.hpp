/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 14:44:39 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;		// MUST BE A REFERENCE BECAUSE IT GETS THE Weapon ARG
//		Weapon		*_weapon;		// CANNOT BE A POINTER IN THIS CASE

	public:

		// Parameterized constructor
		HumanA(std::string name, Weapon &weapon);

		// Destructor
		~HumanA();

		// Member function
		void	attack();
};

#endif
