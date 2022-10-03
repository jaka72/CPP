/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 19:14:25 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl()
{
	init();
}


Harl::~Harl()
{	}


void Harl::init()
{
	data[0].level = "DEBUG";
	data[1].level = "INFO";
	data[2].level = "WARNING";
	data[3].level = "ERROR";

	data[0].pointerToFunction = &Harl::debug;
	data[1].pointerToFunction = &Harl::info;
	data[2].pointerToFunction = &Harl::warning;
	data[3].pointerToFunction = &Harl::error;
//	data[0].pointerToTRIAL = &Harl::trial;

	// a = &Harl::TEST;
	datatest[0].ptf = &Harl::TEST;
}



void Harl::complain(std::string level)
{
	int i = 0;

	while (i < 4)
	{
		if (level == data[i].level)
		{
			// call function pointer
		//	harl[i].pointerToFunction(); // ????
			(this->*(data[i].pointerToFunction))(); // call the correct function
		}
		i++;
	}
//	(this->*(data[0].pointerToTRIAL))(); // call the function

	// (this->*(ptf))();
	(this->*(datatest[0].ptf))();
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n  I love having extra bacon for my 7XL-double-"
				"cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\n  I cannot believe adding extra bacon costs more money. "
				"You didn’t put enough bacon in my burger! If you did, I wouldn’t "
				"be asking for more!\n\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n  I think I deserve to have some extra bacon for free. "
				"I’ve been coming for years whereas you started working here since last month.\n\n";
}


void Harl::error()
{
	std::cout << "[ ERROR ]\n  This is unacceptable! I want to speak to the manager now.\n\n";
}



void Harl::TEST()
{
	std::cout << "TEST:\n";
}