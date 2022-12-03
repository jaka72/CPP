#include "SpellBook.hpp"
// #include "Polymorph.hpp"

//Default constructor
SpellBook::SpellBook()
{

}

//Param. constructor

//Copy constructor
SpellBook::SpellBook(SpellBook const &other)
{
	*this = other;
}

//Destructor
SpellBook::~SpellBook()
{

}

//Overload operator=
SpellBook &SpellBook::operator=(SpellBook const &)
{

	return(*this);
}

//Getters

//Setters

//Public member functions
void SpellBook::learnSpell(ASpell* spell)
{
	std::cout << BLU << "called learnSpell (from SpellBook), spellName ["  << spell->getName() << "]\n" RES;
	
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




void SpellBook::forgetSpell(std::string const &spellName)
{
	std::cout << BLU"called Forget Spell, name " << spellName << ",  vect.size: " << vect.size() << "\n" RES;

	std::vector<ASpell*>::iterator it = vect.begin(); 	//     vect    IS NOT A POINTER, NO ->
														// BUT vect[0] IS A POINTER, THE SPELL*
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellName)
			vect.erase(it);
	}

	if (vect.size() != 0)
	{
		//std::cout << BLU"Forget spell, vect size: " << vect.size() << "\n" RES;
		std::cout << BLU"Forget spell,  getname() " <<   (*it)->getName() << "\n" RES;	// Still has the name after erase() ???
		//std::cout << BLU"Forget spell, IT getname " << (*(*it)).getName() << "\n" RES;
	}
	else
		std::cout << BLU"No spell to forget, the vector is empty\n" RES;

}



// Searches in the vector and if it finds this spellname, it returns a new object with this name 
ASpell* SpellBook::createSpell(std::string const &spellName)
{
	std::cout << BLU"SpellBook, createSpell() \n" RES;

	std::vector<ASpell*>::iterator it = vect.begin();
	for ( ; it != vect.end() ; it++ )
	{
		if ((*it)->getName() == spellName)
		{
			std::cout << BLU"    spellName found (" << (*it)->getName() << "), return its clone \n" RES;
			return ((*it)->clone());
		}
	}
	std::cout << BLU"    spellName NOT found (" << spellName << "), return NULL \n" RES;
	return (NULL);
}

