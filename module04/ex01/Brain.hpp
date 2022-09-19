#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include "colors.h"

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
		static const int	nr_ideas = 100;	// not sure if it is allowed ot add other vars
		std::string			_ideas[nr_ideas];

	public:

		// Constructors
		Brain();
		//Brain(std::string &type); // not sure to leave the &
		Brain(const Brain &brain);

		// Destructor
		~Brain();

		// Overload operators
		Brain &operator= (const Brain &brain);

		// Public member functions

		// Setter
		void setIdea(int n, std::string idea);

		// Getters
		const std::string getIdea(int n) const;
		const std::string *getIdeaAdres(int n) const;

		// int getNr_ideas();


};

#endif
