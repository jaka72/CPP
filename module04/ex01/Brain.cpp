#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GRE"Default Constructor: Brain" << RES << std::endl;
	//nr_ideas = 100;

}


Brain::Brain(const Brain &copy) //: Animal()
{
	std::cout << "Copy Constructor: Brain" << std::endl;
	*this = copy;
}


Brain &Brain::operator= (const Brain &brain)
{
	if (this == &brain)
		return (*this);
	//this->_ideas = brain._ideas;


	// HOW TO COPY STRINGS HERE ?????????
	int i = 0;
	// while (i < 100)
	while (i < nr_ideas)
	{
		(this->_ideas[i]) = (brain._ideas[i]);
		i++;
	}

	return (*this);
}


Brain::~Brain()
{
	std::cout << GRE"Destructor: Brain" << RES << std::endl;
}


// Setter
void Brain::setIdea(int n, std::string idea)
{
	// if (n > 100)
	if (n > nr_ideas)
		std::cout << "The array Ideas can have max 100 entries";
	else
		this->_ideas[n] = idea;
}


// Getters
const std::string Brain::getIdea(int n) const // MAYBE const WAS MISSING ???
{
	if (n < 100)
		return (this->_ideas[n]);
	return ("Error: The array Ideas can have max 100 entries");	 
}


const std::string *Brain::getIdeaAdres(int n) const
{
	//std::cout << "GetIdeaAdres, nr_ideas: " << nr_ideas << "\n";	 
	if (n < nr_ideas)
	{
		const std::string &adres = this->_ideas[n];
		return (&adres);
	}
	return (NULL);
}
