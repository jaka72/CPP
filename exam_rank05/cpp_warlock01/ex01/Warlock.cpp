#include "Warlock.hpp"

//Default constructor
Warlock::Warlock()
{

}



//Param. constructor
Warlock::Warlock(std::string name, std::string tl) : name(name), title(tl)
{
	std::cout << this->name << ": This looks like another boring day.\n";
}




//Copy constructor
Warlock::Warlock(Warlock const &)
{

}

//Destructor
Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!\n";
}

//Overload operator=
Warlock &Warlock::operator=(Warlock const &)
{

	return(*this);
}

//Getters

//Setters

//Public member functions

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << name << ", " << title << "!\n";
}


std::string const Warlock::getName() const
{
	return (name);
}

std::string const Warlock::getTitle() const
{
	return (title);
}

void Warlock::setTitle(std::string const &str)
{
	title = str;
}



void Warlock::learnSpell(ASpell *spell)
{
	std::vector<ASpell*>::iterator it = vect.begin();
	for ( ; it != vect.end() ; it++ )
	{
		// if (vect.size() == 0)
		// 	break ;
		if ((*it)->getName() == spell->getName())
			return ;
	}
	vect.push_back(spell); // DOES IT NEED TO BE CLONED HERE AND THEN DELETED IN THE FORGET() ???
}



void Warlock::forgetSpell(std::string spellname)
{
	std::vector<ASpell*>::iterator it = vect.begin();
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellname)
			vect.erase(it);
	}
}


void Warlock::launchSpell(std::string spellname, ATarget & target)
{
	std::vector<ASpell*>::iterator it = vect.begin();
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellname)
			(*it)->launch(target);
	}
}