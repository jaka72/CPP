#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>
#include <vector>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
		std::vector<ATarget*> vect;
		TargetGenerator(TargetGenerator const &other);
		TargetGenerator &operator=(TargetGenerator const &other);

	public:
		//Constructors
		TargetGenerator();
		~TargetGenerator();

		//Overload operator=

		//Getters

		//Setters

		//Public member functions
		void learnTargetType(ATarget*);
		void forgetTargetType(std::string const &);
		ATarget* createTarget(std::string const &);

};
