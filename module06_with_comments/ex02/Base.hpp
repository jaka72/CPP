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


#ifndef Base_H
#define Base_H

#include <iostream>
#include "colors.h"
// #include "A.hpp"	// HERE CHILD MAKES ERROR, expected classname 
// #include "B.hpp"	//                          before {
// #include "C.hpp"






class Base
{
	protected:
		// int			_id;
		// std::string	_name;
		

	public:
		int	_dummy;

		// Constructor
		
		// Param. constr.

		// Copy constructor

		// Destructor
		virtual ~Base();

		// Overload operators
		// Serialize &operator= (const Serialize &src);


		// Public member functions

		
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









