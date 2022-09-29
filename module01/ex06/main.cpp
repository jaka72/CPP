/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 12:06:29 by jaka          #+#    #+#                 */
/*   Updated: 2022/09/29 12:52:21 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "Harl.hpp"

/*
	Constr and Destrucor must always have (), like a function!

	Typedef can be defined in class-public, then also declared as an array. 

	In the struct, the funToPointer declaration must repeat Harl::
			The whole name after type must be in brackets,
			The star * comes after colons, before the name
				void (Harl :: * funcName) (void)
*/


/*
	POINTER TO FUNCTION SYNTAX:
	To call the function pointer from inside of another function (complain):
			Whole name must be in brackets
			Must start with this->
			After this is a star *
			Then again the whole name inside brackets
			(this -> * (harl[i] . pointerName )) ()

	In the init(), when assigning the funcPointer to struct member, 
		the name of the function must have the & and then the class name, without ()
			harl[i].pointerToFunction = &Harl::debug;

	Sometimes the class name Harl:: must be repeated again inside a function, 
		even if the function name already has it ( void Harl::init ) ...
*/



int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <arg>\n";
		std::cout << "       (DEBUG, INFO, WARNING, ERROR)\n";
		return (1);
	}

	std::string str = argv[1];
	
	int ret;
	int i = 0;
	while (i < 4)
	{
		ret = str.compare((harl.data[i]).level);
		if (ret == 0)
			break ;
		//std::cout << "comparison: " << ret << "\n";
		i++;
	}

	switch(i)
	{
		case 0:
			harl.call_complaints(i);
			break ;
		case 1:
			harl.call_complaints(i);
			break ;
		case 2:
			harl.call_complaints(i);
			break ;
		case 3:
			harl.call_complaints(i);
			break ;
		default:
			std::cout << "Usage: ./harlFilter <arg>\n";
			std::cout << "       (DEBUG, INFO, WARNING, ERROR)\n";
	}

}