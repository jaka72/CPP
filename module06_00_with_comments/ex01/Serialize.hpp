/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/03 13:59:58 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef Serialize_H
#define Serialize_H

#include <stdint.h>		// for type uintptr_t
// #include <cstdint>		// for type uintptr_t
#include <iostream>
#include "colors.h"



struct Data
{
	int			id;
	std::string name;
	Data		*next;
};





class Serialize
{
	private:
		int	_dummy;
		// int			_id;
		// std::string	_name;
		

	public:

		// Constructor
		Serialize();
		
		// Param. constr.
		Serialize(int id, std::string name);

		// Copy constructor
		Serialize(const Serialize &src);

		// Destructor
		~Serialize();

		// Overload operators
		Serialize &operator= (const Serialize &src);


		// Public member functions
		uintptr_t	serialize(Data* d);
		Data*		deserialize(uintptr_t i);

		
		// Getter
		// int			getId();
		// std::string getName();



		// Setter


		// Exceptions


};

// THIS IS OUTSIDE OF THE CLASS !!!
// std::ostream& operator<< (std::ostream& outstream, Serialize &d)
// {
// 	outstream << "Serialize, " <<  d.getId()<<  d.getName() <<"\n";
// 	return (outstream);
// }

#endif

/////////////////////////////////////////////////////////////////////









