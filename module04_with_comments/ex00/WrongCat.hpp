/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 13:35:31 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 14:34:14 by jmurovec      ########   odam.nl         */
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

		//Cat(std::string &type); // not sure to leave the &

		// Copy constructor
		WrongCat(const WrongCat &wrcat);

		// Destructor
		~WrongCat();

		// Overload operators
		WrongCat &operator= (const WrongCat &wrcat);

		// Public member functions
		void makeSound(void) const;

		// Getter
		void getType() const;

		// Setter
		void setType(std::string type);
};

#endif
