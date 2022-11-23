/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialize.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/23 13:07:52 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZE_H
#define SERIALIZE_H

//#include <stdint.h>	// for type uintptr_t
#include <cstdint>		// for type uintptr_t
#include <iostream>
#include "data.hpp"
#include "colors.h"




class Serialize
{
	private:
		// int	_dummy;		

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


// std::ostream& operator<< (std::ostream& outstream, Serialize &d)
// {
// 	outstream << "Serialize, " <<  d.getId()<<  d.getName() <<"\n";
// 	return (outstream);
// }

#endif

/////////////////////////////////////////////////////////////////////









