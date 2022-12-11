#include "TargetGenerator.hpp"

//Default constructor
TargetGenerator::TargetGenerator()
{
	std::cout << GRE "Default constr (TargetGenerator)\n";

}

//Param. constructor

//Copy constructor
TargetGenerator::TargetGenerator(TargetGenerator const &)
{
	// *this = other;
}

//Destructor
TargetGenerator::~TargetGenerator()
{

}

//Overload operator=
TargetGenerator &TargetGenerator::operator=(TargetGenerator const &)
{
	return(*this);
}

//Getters

//Setters

//Public member functions

void TargetGenerator::learnTargetType(ATarget* trg)
{
	std::cout << LRD "TargetGenerator: learnTargeType()\n";

	std::vector<ATarget*>::iterator it = this->vect.begin();
	for ( ; it != this->vect.end()  ; it++ )
	{
		if ((*it)->getType() == trg->getType())
		{
			std::cout << LRD "   This type of target exists, dont have to learn\n";
			return ;
		}
	}
	this->vect.push_back(trg);
}


void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::cout << LRD "TargetGenerator: forgetTargeType()\n";
	std::vector<ATarget*>::iterator it = this->vect.begin();
	for ( ; it != this->vect.end()  ; it++ )
	{
		std::cout << LRD "   loop, vect.size: " << this->vect.size() << "\n";

		if ((*it)->getType() == type)
		{
			std::cout << LRD "   erasing " << type << "\n" RES;
			this->vect.erase(it);
			std::cout << LRD "         j)\n";
			if (this->vect.size() == 0)
				return ;
		}
		std::cout << LRD "      i)\n";
	}
	std::cout << LRD "   k)\n";
}


ATarget* TargetGenerator::createTarget(std::string const &type)
{
	std::cout << GRE"TargetGenerator: Create Target()\n" RES;

	std::vector<ATarget*>::iterator it = vect.begin();
	for ( ; it != vect.end()  ; it++ )
	{
		if ((*it)->getType() == type)
		{
			std::cout << LRD "   This type of target exists, so it can be creaed/returned\n";
			return ((*it)->clone());
		}
	}
	return (NULL);
}

