/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:26 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:23:31 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
/*
 * < HumanB >
 * - HumanB는 생성자에서 Weapon을 사용한다.
 * - HumanB는 항상 무장하고 있다.
 */
#include "Weapon.hpp"

class HumanB{
public:
	HumanB(std::string name_orig);
	void setWeapon(Weapon& _weapon);
	void attack(void);

private:
	std::string name_private;
	std::string weapon_type_;
};
#endif
