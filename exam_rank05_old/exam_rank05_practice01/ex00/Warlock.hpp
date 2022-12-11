#pragma once

/*
**==========================
**		Includes
**==========================
*/

#include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;

		// Warlock bob;  // Check if this reaaly does not compile! //Does not compile
		Warlock();
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);

	public:
		//Constructors
		Warlock(std::string name, std::string title);
		~Warlock();

		//Overload operator=


		// Both these functions will have to be callable on a constant Warlock. ???
		//Getters
		std::string const getName() const;
		std::string const getTitle() const;

		//Setters
		void setTitle(std::string const &str);

		//Public member functions
		void introduce() const;

};
