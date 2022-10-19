/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 20:40:18 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/19 20:19:55 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor
Brain::Brain()
{
	std::cout << GRE"      Default Constructor: Brain" << RES << "\n";
}


// Copy constructor
Brain::Brain(const Brain &copy)
{
	std::cout << GRE"      Copy Constructor: Brain" << RES << "\n";
	*this = copy;
}

// Overload operator
Brain &Brain::operator= (const Brain &brain)
{
	std::cout << GRE"      Overload assignment operator (Brain)\n" << RES;
	if (this == &brain)
		return (*this);

	int i = 0;
	while (i < _nr_ideas)		// HOW TO COPY STRINGS ???
	{
		(this->_ideas[i]) = (brain._ideas[i]);
		i++;
	}
	return (*this);
}


// Destructor
Brain::~Brain()
{
	std::cout << GRE"      Destructor: Brain" << RES << std::endl;
}


// Setter
void Brain::setIdea(int n, std::string idea)
{
	if (n > _nr_ideas)
		std::cout << "The array Ideas can have max 100 entries";
	else
		this->_ideas[n] = idea;
}


// Getters
const std::string Brain::getIdea(int n) const
{
	if (n < 100)
		return (this->_ideas[n]);
	return ("Error: The array Ideas can have max 100 entries");	 
}


// Public member functions
const std::string *Brain::getIdeaAdres(int n) const
{
	//std::cout << "GetIdeaAdres, nr_ideas: " << nr_ideas << "\n";	 
	if (n < _nr_ideas)
	{
		const std::string &adres = this->_ideas[n];
		return (&adres);
	}
	return (NULL);
}
