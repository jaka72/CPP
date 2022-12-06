/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/12/06 16:11:28 by jmurovec      ########   odam.nl         */
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
		Weapon		&_weapon;

	public:

		// Parameterized constructor
		HumanA(std::string name, Weapon &weapon);

		// Destructor
		~HumanA();

		// Member function
		void	attack();
};

#endif
