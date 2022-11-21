/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/04 08:45:54 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

// Constructor
Serialize::Serialize() 
{
	std::cout << GRE"Default constr (Serialize) " << "\n" RES;
	// _id = 0;
	// _name = "Default_name";
}


// Param. constr.
Serialize::Serialize(int, std::string)
{
	// std::cout << GRE"Param. constructor (Serialize), id: [" << _id << "], "
	// 									"name: [" << _name << "],  \n" RES;
	// _id = id;
	// _name = name;
}



// Copy constructor
Serialize::Serialize(const Serialize &src)
{
	std::cout << GRE"Copy constructor:   " << "\n" RES;
	*this = src;
}



// Overload operators
Serialize& Serialize::operator= (const Serialize &src)
{
	std::cout << GRE"Overload operator=  (Serialize)" << "\n" RES;
	_dummy = src._dummy;
	// _name = src._name;
	return *this;
}


// Destructor
Serialize::~Serialize()
{
	std::cout << GRE"Destructor (Serialize) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions
// int Serialize::getId()
// {
// 	std::cout << "ID: " << _id << "\n";
// 	return (_id);
// }


// std::string Serialize::getName()
// {
// 	std::cout << "Name: " << _name << "\n";
// 	return (_name);
// }



uintptr_t	Serialize::serialize(Data* ptr)
{
	uintptr_t	i;
	i = reinterpret_cast<uintptr_t>(ptr);
	
	std::cout << MAG"   Called function serialize()\n" RES;
	std::cout << MAG"   The Pointer is now stored into uintptr\n" RES;
	
	return (i);
}


Data*		Serialize::deserialize(uintptr_t raw)
{
	std::cout << MAG"   Called function deserialize()\n" RES;
	std::cout << MAG"   The uintptr is now returned to a pointer\n" RES;
	
	return (reinterpret_cast<Data*>(raw));
}
