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
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(Warlock const &other);
		Warlock &operator=(Warlock const &other);


	public:
		//Constructors
		Warlock(std::string name, std::string title);
		~Warlock();


		// Getters
		const std::string& getName() const;
		const std::string& getTitle() const;

		// Setters
		void setTitle(std::string str);

		void introduce() const;


};
