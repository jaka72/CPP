/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 12:06:27 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 12:40:57 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	 _name;
		Weapon		&_wp;		// WHY A REFERENCE ???

	public:

		HumanA(std::string name, Weapon &wp_orig);

		~HumanA();

		void	attack();
};

#endif
