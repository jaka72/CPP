/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:22:40 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:23:11 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name_orig, Weapon& _weapon)
{
	name_private = name_orig;
	weapon_type_ = _weapon.getType();
}

void HumanA::attack(void)
{
	std::cout << name_private << " attacks with his " << weapon_type_ << std::endl;
}
