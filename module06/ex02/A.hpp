/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.hpp			                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 16:46:59 by jaka          #+#     #                  */
/*   Updated: 2022/11/03 13:59:58 by jaka          ######## odam.nl  		  */
/*                                                                            */
/* ************************************************************************** */


#ifndef A_H
#define A_H

#include <iostream>
#include "colors.h"
#include "Base.hpp"

// PROBABLY SHOULD DELETE CONSTRUCTORS A, B ,C , BECAUSE SUBJECTS SAYS MUST ME EMPTY CLASS !!

class A	: public Base
{
	private:

	public:

		// Constructor
		A();

		// Param. constr.

		// Copy constructor

		// Destructor
		//~A();

		// Overload operators

		// Serialize &operator= (const Serialize &src);

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
