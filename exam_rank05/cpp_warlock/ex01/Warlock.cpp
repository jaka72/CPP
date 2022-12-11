

#include "Warlock.hpp"

//Constructors
Warlock::Warlock()
{	}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << GRE << _name << ": This looks like another boring day.\n" RES;
}


Warlock::Warlock(Warlock const &other)
{
	*this = other;
}

Warlock::~Warlock()
{
	std::cout << GRE << this->_name << ": My job here is done.\n" RES;
	// std::cout << this->getName() << ": My job here is done.\n";
}

Warlock &Warlock::operator= (Warlock const &other)
{
	this->_name = other._name;
	this->_title = other._title;
	//*this = other;
	return(*this);
}


// Getters
const std::string& Warlock::getName() const
{
	return (_name);
}

const std::string& Warlock::getTitle() const
{
	return (_title);
}

// Setters
void Warlock::setTitle(std::string str)
{
	_title = str;
}



// Member functions
void Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!\n"; 

}


void Warlock::learnSpell(ASpell* spell)
{
	std::cout << BLU << "called learnSpell, spellName ["  << spell->getName() << "]\n" RES;
	
	std::vector<ASpell*>::iterator it = vect.begin(); 	//     vect    IS NOT A POINTER, NO ->
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spell->getName())
		{
		    std::cout << "      this name already exists, return.\n" RES;
			return ;
		}
	}
	vect.push_back(spell);
}




void Warlock::forgetSpell(std::string spellName)
{
	std::cout << BLU"called Forget Spell, name " << spellName << ",  vect.size: " << vect.size() << "\n" RES;

	std::vector<ASpell*>::iterator it = vect.begin(); 	//     vect    IS NOT A POINTER, NO ->
														// BUT vect[0] IS A POINTER, THE SPELL*
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellName)
			vect.erase(it);
	}



	// if (std::find(vect.begin(), vect.end(), ))
	//std::cout << "Forget spell, name " <<   (*it)->getName() << "\n";
	//std::cout << "Forget spell, name " << (*(*it)).getName() << "\n";	// WHATS THE CATCH HERE??
	//vect.erase(it);
	if (vect.size() != 0)
	{
		std::cout << BLU"Forget spell, vect size: " << vect.size() << "\n" RES;
		std::cout << BLU"Forget spell,  getname() " <<   (*it)->getName() << "\n" RES;	// Still has the name after erase() ???
		std::cout << BLU"Forget spell, IT getname " << (*(*it)).getName() << "\n" RES;
	}
	else
		std::cout << BLU"No spell to forget, the vector is empty\n" RES;
}





void Warlock::launchSpell(std::string spellName, ATarget& trg)
{
	std::cout << MAG"called launchSpell, name " << spellName << ",   target, type " << trg.getType() << "\n" RES;
	std::cout <<  MAG"    spell get name " << vect[0]->getName() << "\n" RES;
	// if (vect[0]->getName() == spellName)
	// {
	// 	std::cout << "FOUND SPELL\n";
	// 	vect[0]->launch(trg);
	// }


	std::vector<ASpell*>::iterator it = vect.begin(); 	//     vect    IS NOT A POINTER, NO ->
														// BUT vect[0] IS A POINTER, THE SPELL*
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellName)
			(*it)->launch(trg);
	}
}
