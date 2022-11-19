/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 17:59:25 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/05 13:49:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "A.hpp"
#include "Base.hpp"

// Constructor
// Base::Base() 
// {
// 	std::cout << GRE"Default constr (Base) " << "\n" RES;
// 	// _id = 0;
// 	// _name = "Default_name";
// }


// Param. constr.
// Base::Base(int, std::string)
// {
// 	// std::cout << GRE"Param. constructor (Base), id: [" << _id << "], "
// 	// 									"name: [" << _name << "],  \n" RES;
// 	// _id = id;
// 	// _name = name;
// }



// Copy constructor
// Base::Base(const Base &src)
// {
// 	std::cout << GRE"Copy constructor:   " << "\n" RES;
// 	*this = src;
// }



// Overload operators
// Base& Base::operator= (const Base &src)
// {
// 	std::cout << GRE"Overload operator=  (Base)" << "\n" RES;
// 	_dummy = src._dummy;
// 	// _name = src._name;
// 	return *this;
// }


// Destructor
Base::~Base()
{
	std::cout << GRE"Destructor (Base) " << "\n" RES;
}


//////////////////////////////////////////////////////////

// Public member functions
// int Base::getId()
// {
// 	std::cout << "ID: " << _id << "\n";
// 	return (_id);
// }


// std::string Base::getName()
// {
// 	std::cout << "Name: " << _name << "\n";
// 	return (_name);
// }

