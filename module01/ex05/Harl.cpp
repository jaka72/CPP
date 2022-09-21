/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/21 19:02:53 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::init()
{
	data[0].level = "debug";
	data[1].level = "info";
	data[2].level = "warning";
	data[3].level = "aaa";

	data[0].pointerToFunction = &Harl::debug; // how to write this
	data[1].pointerToFunction = &Harl::info; // how to write this
	data[2].pointerToFunction = &Harl::warning; // how to write this
	data[3].pointerToFunction = &Harl::aaa; // how to write this
}

Harl::Harl()  // ????
{
	init();
}


Harl::~Harl()
{
}
