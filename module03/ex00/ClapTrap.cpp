#include "ClapTrap.hpp"

// Where to initialize these values ???

// Constructor Default
ClapTrap::ClapTrap(std::string name)
{
	m_name = name;
	hit_pts = 10;
	energy_pts = 10;
	attack_damage = 0;
}

// Constructor Copy
ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	*this = claptrap;
}

// Destructor
ClapTrap::~ClapTrap()
{
}

//	HERE ALL MEMBERS ARE COPIED ONE-BY-ONE, SO THAT
// 	THE COPY CONSTRUCTOR CAN BE SIMPLIFIED WITH *this = orig
ClapTrap &ClapTrap::operator= (const ClapTrap &orig)
{
	if (this == &orig)
		return (*this);
	this->m_name = orig.m_name;
	this->hit_pts = orig.hit_pts;
	this->energy_pts = orig.energy_pts;
	this->attack_damage = orig.attack_damage;
	return (*this);
}

// Public member functions
void	ClapTrap::attack(const std::string &target)
{
	if (energy_pts <= 0 || hit_pts <= 0)
	{
		std::cout << m_name << " can't attack, because has no energy" 
			" points left.\n"; 
		return ;
	}
	// attack_damage++;
	if (energy_pts > 0)
	{	std::cout << this->m_name << " attacks " << target <<
			", causing him " << attack_damage << " points of damage!\n";
		energy_pts--;
		std::cout << "   (" << m_name << " now has "<<  energy_pts <<
			" energy points left)\n\n";
	}
	//else
	//	std::cout << m_name << " now has zero energy points and died.\n\n";
	// 
}



void	ClapTrap::takeDamage(unsigned int amount)
{
	//attack_damage++; // 	DOES THIS BELONG HERE ??
	std::cout << this->m_name << " takes damage of "
		<< amount << " points\n";
	hit_pts -= amount;
	if (hit_pts > 0)
		std::cout << "   (Now he has " << hit_pts << " hit_points left)\n\n";
	else
	{
		hit_pts = 0;
		std::cout << "   (Now he has zero hit points and died)\n\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_pts <= 0)
	{
		std::cout << m_name << " can't be repaired, because he has no energy" 
			" points left\n"; 
		return ;
	}
	hit_pts += amount;
	energy_pts--;
	std::cout << this->m_name << " repaires himself by amount " 
		<< amount << "!\n";
	std::cout << "   (Now he has " << hit_pts << " hit points)\n\n";
}
