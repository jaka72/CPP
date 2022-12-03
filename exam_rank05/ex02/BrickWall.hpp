#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>
#include "ATarget.hpp"

class BrickWall : public ATarget
{
	private:

	public:
		//Constructors
		BrickWall();
		BrickWall(BrickWall const &other);
		~BrickWall();

		//Overload operator=
		BrickWall &operator=(BrickWall const &other);

		//Getters

		//Setters

		//Public member functions

		// pure
		BrickWall* clone() const;
};
