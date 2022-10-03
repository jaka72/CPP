/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/28 20:36:52 by jaka          ########   odam.nl         */
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
	data[0].level = "debug";
	data[1].level = "info";
	data[2].level = "warning";
	data[3].level = "error";
	data[0].level = "trial";

	data[0].pointerToFunction = &Harl::debug; // how to write this
	data[1].pointerToFunction = &Harl::info; // how to write this
	data[2].pointerToFunction = &Harl::warning; // how to write this
	data[3].pointerToFunction = &Harl::error; // how to write this
//	data[0].pointerToTRIAL = &Harl::trial; // how to write this
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
			(this->*(data[i].pointerToFunction))(); // call the function
		}
		i++;
	}
//	(this->*(data[0].pointerToTRIAL))(); // call the function
}

void Harl::debug()
{
	std::cout << "Debug:   I love having extra bacon ...\n";
}

void Harl::info()
{
	std::cout << "Info:    I cannot believe ... \n";
}

void Harl::warning()
{
	std::cout << "Warning: I think I deserve to ...\n";
}


void Harl::error()
{
	std::cout << "Error:   This is unacceptable ...\n";
}

// int Harl::trial()
// {
// 	int a = 33;
// 	std::cout << "trial: .......................\n";
// 	return (a);
// }