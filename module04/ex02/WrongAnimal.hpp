/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 09:53:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 13:27:50 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>
#include "colors.h"

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
	
		// Constructor
		WrongAnimal();

		// Param. constr.
		WrongAnimal(std::string &type);

		// Copy constructor
		WrongAnimal(const WrongAnimal &src);

		// Destructor
		virtual ~WrongAnimal();

		// Overload operators
		WrongAnimal &operator= (const WrongAnimal &src);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;

		// Setter
		virtual void setType(std::string type);
};

#endif
