/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:44:38 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/20 10:48:48 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include "colors.h"
#include "Animal.hpp"

/*

	Class Brain does not have to inherit class : Animal, because Brain will
	be used differently than Cat() : Animal()
	An object Brain will be created in the Cat's constructor:
			this->_brain = new Brain() 
		So, Cat will have acces to the object Brain's and to
		the private array Ideas inside Brain
*/

class Brain //: public Animal
{
	private:
	
		static const int	_nr_ideas = 100;	// not sure if it is allowed to add other vars
		std::string			_ideas[_nr_ideas];

	public:

		// Constructors
		Brain();

		Brain(const Brain &brain);

		// Destructor
		~Brain();

		// Overload operators
		Brain &operator= (const Brain &brain);

		// Public member functions

		// Setter
		void setIdea(int n, std::string idea);

		// Getters
		const std::string  getIdea(int n) const;
		const std::string *getIdeaAdres(int n) const;
};

#endif
