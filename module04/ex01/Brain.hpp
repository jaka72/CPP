/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 19:44:38 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/21 12:57:11 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include "colors.h"
#include "Animal.hpp"



class Brain
{
	private:
	
		static const int	_nr_ideas = 100;
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
