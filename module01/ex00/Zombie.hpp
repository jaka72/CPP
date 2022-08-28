#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;
	
	public:
		Zombie(std::string name_public)
		{
			name = name_public;
		}
		~Zombie(void)
		{
			std::cout << name << " destroyed.\n";
		}
		void	announce(void);
};

Zombie *newZombie(std::string name);
void    randomChump(std::string name);

#endif