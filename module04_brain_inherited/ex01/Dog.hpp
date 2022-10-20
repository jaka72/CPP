/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:58:01 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 16:07:35 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal, public Brain
{
	private:

		std::string		_type;
		//Brain			*_brain;

	public:
	
		// Constructors
		Dog();

		// Param. constr.
		Dog(std::string type);

		// Copy constructor
		Dog(const Dog &dog);

		// Destructor
		~Dog();

		// Overload operators
		Dog &operator= (const Dog &dog);

		// Public member functions
		void makeSound(void) const;


		// Setter
		void setIdea(int n, std::string idea);
		void setType(std::string type);


		// Getters
		void		getIdea(int n) const;
		std::string	getType() const;

};

#endif
