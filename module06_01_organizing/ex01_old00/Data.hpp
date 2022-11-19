/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/03 13:59:58 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_H
#define DATA_H

#include <stdint.h>		// for type uintptr_t
// #include <cstdint>		// for type uintptr_t
#include <iostream>

#include "colors.h"



class Data
{
	private:
		int			_id;
		std::string	_name;
		

	public:

		// Constructor
		Data();
		
		// Param. constr.
		Data(int id, std::string name);

		// Copy constructor
		Data(const Data &src);

		// Destructor
		~Data();

		// Overload operators
		Data &operator= (const Data &src);


		// Public member functions
		uintptr_t	Serialize(Data* d);
		Data*		Deserialize(uintptr_t i);

		
		// Getter
		int			getId();
		std::string getName();



		// Setter


		// Exceptions


};

// THIS IS OUTSIDE OF THE CLASS !!!
// std::ostream& operator<< (std::ostream& outstream, Data &d)
// {
// 	outstream << "Data, " <<  d.getId()<<  d.getName() <<"\n";
// 	return (outstream);
// }

#endif

/////////////////////////////////////////////////////////////////////









