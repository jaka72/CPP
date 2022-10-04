/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 19:02:33 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/04 11:40:10 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"


/*
	Constr and Destrucor must always have (), like a function!

	Typedef can be defined in class-public, then also declared as an array. 

	In the struct, the funToPointer declaration must repeat Harl::
			The whole name after type must be in brackets,
			The star * comes after colons, before the name
				void (Harl :: * funcName) (void)


	Don't forget Class::  in front of every function definition


	To call the function pointer from inside of another function (complain):
			Whole name must be in brackets
			Must start with this->
			After this is a star *
			Then again the whole name inside brackets
			(this -> * (harl[i] . pointerName )) ()

	In the init(), when assigning the funcPointer to struct member, 
		the name of the function must have the & nad then the class name, without ()
			harl[i].pointerToFunction = &Harl::debug;

	Sometimes the class name Harl:: must be repeated again inside a function, 
		even if the function name already has it ( void Harl::init ) ...
*/



int main()
{
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	harl.complain("trial");
}


/*
	VAJA - POINTER TO FUNCTION
		A) Declaration in the Public:
			void (TestClass::*fpt)();
			
		B) Assign a custom function to the pointer function, in init()
			fpt 		= &TestClass::print;
			data[0].fpt = &TestClass::print; 

		C) Call the pointer function from inside a public member function
			(this->*(fpt))()
			(this->*(data[0].fpt))()
*/
