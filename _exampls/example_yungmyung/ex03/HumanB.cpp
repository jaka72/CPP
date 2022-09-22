/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:20 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:23:23 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name_orig)
{
	name_private = name_orig;
}

void HumanB::setWeapon(Weapon& _weapon)
{
	weapon_type_ = _weapon.getType();
}

void HumanB::attack(void)
{
	std::cout << name_private << " attacks with his " << weapon_type_ << std::endl;
}