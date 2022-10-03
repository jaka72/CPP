/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:33 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 18:57:20 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"


/*
	Typedef can be defined in class-public, then also declared as an array. 

	In the struct, the funToPointer declaration must repeat Harl::
			The whole name after type must be in brackets,
			The star * comes after colons, before the name
				void (Harl :: * funcName) (void)


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



int main()
{
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	//harl.a->ptf = &Harl::TEST;

	//harl.TEST();
	// harl.datatest[0]();
	// harl.*(datatest[0].ptf)();

}


/*
	VAJA - POINTER TO FUNCTION
		A) Declaration in the struct in the Public member:
			void (Harl::*ptf)(void)
			
		B) Assign a custom function to the pointer function, in init()
			data.ptf = &Harl::TEST;

		C) Call the pointer function from inside a public member function
			(this->*(data[0].ptf))();
*/