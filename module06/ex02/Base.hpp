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

class Base
{
	protected:

	public:
		// Constructor
		
		// Param. constr.

		// Copy constructor

		// Destructor
		virtual ~Base();

		// Overload operators
	
		// Public member functions
		
		// Getter

		// Setter

		// Exceptions
};

// std::ostream& operator<< (std::ostream& outstream, Serialize &d)
// {
// 	outstream << "Serialize, " <<  d.getId()<<  d.getName() <<"\n";
// 	return (outstream);
// }

#endif
