/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/23 13:00:58 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Serialize.hpp"


int main()
{
	{
		
		std::cout << BLU"Declare 2 pointers to structs Data:\n" RES;
		Data* d0;
		Data* d1;
		std::cout << "  Address of Data d0: " << d0 << "\n";
		std::cout << "  Address of Data d1: " << d1 << "\n\n";


		std::cout << BLU"Initialize d0:\n" RES;
		d0 = new Data;
		std::cout << "  Address of Data d0: " << d0 << "\n";
		std::cout << "  Address of Data d1: " << d1 << "\n\n";
		
		
		std::cout << BLU"Give values to d0:\n" RES;
		d0->id 		= 33;
		d0->name 	= "Mitch";
		d0->next 	= NULL;

		std::cout << "d0:\n  address: " << d0 << "\n  id:      " << d0->id << "\n  name:    " << d0->name <<"\n\n";
		
		
		std::cout << BLU"Declare object Serialize:\n" RES;
		Serialize	s;

		
		std::cout << BLU"\nConvert pointer d0 to type uintptr_t via function serialize()\n" RES;
		uintptr_t	i = s.serialize(d0);

		std::cout << BLU"\nConvert uintptr_t to a pointer d1\n" RES;
		d1 = s.deserialize(i);
		
		std::cout << BLU"\nCheck values of both:\n" RES;
		std::cout << "d0:\n  address: " << d0 << "\n  id: " << d0->id << "\n  name: " << d0->name <<"\n";		
		std::cout << "d1:\n  address: " << d1 << "\n  id: " << d1->id << "\n  name: " << d1->name <<"\n\n";		
		delete d0;
		// delete d1;	
	}
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Data d0, *d1;
		
		d0.id 	= 77;
		d0.name = "Bob";
		d0.next = NULL;

		std::cout << "d0:\n  address: " << &d0 << "\n  id:      " << d0.id << "\n  name:    " << d0.name <<"\n";		
		
		Serialize	s;
		uintptr_t	i;
		
		i = s.serialize(&d0);
		
		d1 = s.deserialize(i);
		std::cout << "d1:\n  address: " << d1 << "\n  id: " << d1->id << "\n  name: " << d1->name <<"\n\n";		
	}
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return 0;
}
