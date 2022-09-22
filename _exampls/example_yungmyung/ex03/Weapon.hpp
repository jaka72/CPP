/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjung <mjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:23:54 by mjung             #+#    #+#             */
/*   Updated: 2021/11/19 20:24:01 by mjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
public:
	std::string getType(void);
	void setType(std::string name_orig);

	Weapon(std::string name_orig);

private:
	std::string weapon_;

};

#endif
