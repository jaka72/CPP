/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:45 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:23:48 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _weaponname_orig)
{
	weapon_ = _weaponname_orig;
}

std::string Weapon::getType(void)
{
	return (weapon_);
}

void Weapon::setType(std::string _weaponname_orig)
{
	weapon_ = _weaponname_orig;
}