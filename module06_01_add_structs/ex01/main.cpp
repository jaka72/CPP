/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/04 13:27:03 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "Serialize.hpp"

// struct Data
// {
// 	int			id;
// 	std::string name;
// 	Data		*next;
// };


/*
	Questions
	- Data needs to be a struct or a class (in separate file)?
	
	- The functions serialize/Deserialize need to be in a class?
*/



int main()
{
	{
		Data* d0;
		Data* d1;
		
		std::cout << BLU"Declare two structs Data:\n" RES;
		std::cout << "  Address of Data d0: " << d0 << "\n";
		std::cout << "  Address of Data d1: " << d1 << "\n\n";


		d0 = new Data;
		std::cout << BLU"Initialize d0:\n" RES;
		std::cout << "  Address of Data d0: " << d0 << "\n";
		std::cout << "  Address of Data d1: " << d1 << "\n\n";
		
		
		std::cout << BLU"Give values to d0:\n" RES;
		d0->id 		= 33;
		d0->name 	= "Mitch";
		d0->next 	= NULL;

		std::cout << "d0:\n  address: " << d0 << "\n  id: " << d0->id << "\n  name: " << d0->name <<"\n\n";
		
		
		std::cout << BLU"Declare object Serialize:\n" RES;
		Serialize	s;

		
		std::cout << BLU"\nConvert pointer d0 to uintptr via function serialize()\n" RES;
		uintptr_t	i = s.serialize(d0);

		std::cout << BLU"\nConvert uintptr to a pointer\n" RES;
		d1 = s.deserialize(i);
		
		std::cout << BLU"\nCheck values of both:\n" RES;
		std::cout << "d0:\n  address: " << d0 << "\n  id: " << d0->id << "\n  name: " << d0->name <<"\n";		
		std::cout << "d1:\n  address: " << d1 << "\n  id: " << d1->id << "\n  name: " << d1->name <<"\n\n";		
		delete d0;
		// delete d1;
		// std::cout << "d0:\n  address: " << d0 << "\n  id: " << d0->id << "\n  name: " << d0->name <<"\n";		
		// std::cout << "d1:\n  address: " << d1 << "\n  id: " << d1->id << "\n  name: " << d1->name <<"\n\n";		
	
	}
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n\n\n";


	{
		Data d0, *d1;
		
		d0.id = 77;
		d0.name = "Bob";
		d0.next = NULL;

		std::cout << "d0:\n  address: " << &d0 << "\n  id: " << d0.id << "\n  name: " << d0.name <<"\n";		
		
		Serialize	s;
		uintptr_t	i;
		
		i = s.serialize(&d0);
		
		d1 = s.deserialize(i);
		std::cout << "d1:\n  address: " << d1 << "\n  id: " << d1->id << "\n  name: " << d1->name <<"\n\n";		
	}
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return 0;
}
