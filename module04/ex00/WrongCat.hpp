/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:35:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 19:40:41 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	
		std::string _type;

	public:

		// Constructors
		WrongCat();

		// Parameterized constr.
		WrongCat(std::string type);

		// Copy constructor
		WrongCat(const WrongCat &src);

		// Destructor
		~WrongCat();

		// Overload operators
		WrongCat &operator= (const WrongCat &src);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;

		// Setter
		void setType(std::string type);
};

#endif
