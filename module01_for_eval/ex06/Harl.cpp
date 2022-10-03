/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:16 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/29 12:56:37 by jaka          ########   odam.nl         */
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
	// data[0].level = "trial";

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


void	Harl::call_complaints(int i)
{
	while (i < 4)
	{
		(this->*(data[i].pointerToFunction))();
		i++;
	}
}


void Harl::debug()
{
	std::cout << "[ DEBUG ]\n  I love having extra bacon ...\n\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\n  I cannot believe ... \n\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n  I think I deserve to ...\n\n";
}


void Harl::error()
{
	std::cout << "[ ERROR ]\n  This is unacceptable ...\n\n";
}

// int Harl::trial()
// {
// 	int a = 33;
// 	std::cout << "trial: .......................\n";
// 	return (a);
// }