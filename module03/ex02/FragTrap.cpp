#include "FragTrap.hpp"

/*
	IN THE BASE CLASS THE MEMBERS ARE INITIALIZED AFTER FUNC()
	BUT HERE IN INHERITED CLASS THEY ARE INITIALIZED AS MEMBERS ???
*/
FragTrap::FragTrap(): ClapTrap()
{
	//hit_pts = 100;		// CAN BE ALSO WITHOUT ->this
	this->hit_pts = 100;	// inherited from Scav
	this->energy_pts = 100;
	this->attack_damage = 30;
	//this->guard = false;
	std::cout << GRE"Default constructor FragTrap called\n" << RES; 
}

/*
	WHY IS IT GOOD TO HAVE THE SAME name IN THE ClapTrap ARGUMENT ???
	IT CREATES HIS PARENT, A Claptrap, BUT IT'S INVISIBLE.
	THE INVISIBLE PARENT CAN HAVE THE SAME name. 
	IT CAN ALSO HAVE ANOTHER STRING OR EMPTY - IN CREATES A ClapTrap OBJECT
	WITH ANOTHER NAME OR DEFAULT.

	You can override parent members, like hit_pts = 100;
	Otherwise, hit_pts will have value 10, which comes from parent Claptrap 
*/
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	hit_pts = 100;
	this->energy_pts = 100;
	this->attack_damage = 30;
	//this->guard = false;
	m_name = name;
	std::cout << GRE"Constructor FragTrap called to create " <<RES<< name << "\n";
	//std::cout << "...Constructor FragTrap called for this->m_name " << this->m_name << "\n";
	//std::cout << "...Constructor FragTrap called for m_name " << m_name << "\n";
	//std::cout << "...Constructor FragTrap called for hit_points " << hit_pts << "\n";
};



FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)	// WHAT IS THIS LAST (copy) ???
{
	std::cout << GRE"Copy Constructor FragTrap called\n" << RES;
	std::cout << GRE"   (It's a copy of the FragTrap " << copy.m_name << "\n" << RES;
}


FragTrap::~FragTrap()
{
	std::cout << GRE"Destructor FragTrap called for " << RES << m_name << "\n"; 
}


// Overloaded operators
FragTrap &FragTrap::operator= (const FragTrap &fragtrap)
{
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	std::cout << CYN"\nFunction highFivesGuys() called from FragTrap " << m_name << RES << "\n"; 
}

