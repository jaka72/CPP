/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 20:05:19 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 13:02:33 by jmurovec      ########   odam.nl         */
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

		// Constructor
		WrongCat();
		
		// Parameterized constr.
		WrongCat(std::string &type);
		
		// Copy constructor
		WrongCat(const WrongCat &src);

		// Destructor
		~WrongCat();

		// Overload operators
		WrongCat &operator= (const WrongCat &wrcat);

		// Public member functions
		void makeSound(void) const;

		// Getter
		std::string getType() const;

		// Setter
		void setType(std::string type);
};

#endif
