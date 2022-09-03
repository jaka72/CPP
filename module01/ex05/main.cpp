#include <iostream>

/*
	Constr and Destrucor must always have (), like a function!

	Typedef can be defined in class-public, then also declared as an array. 

	In the struct, the funToPointer declaration must repeat Harl::
			The whole name after type must be in brackets,
			The star * comes after colons, before the name
				void (Harl :: * funcName) (void)


	Don't forget Class::  in front of every function definition


	To call the function pointer from inside of another function (complain):
			Whole name must be in brackets
			Must start with this->
			After this is a star *
			Then again the whole name inside brackets
			(this -> * (harl[i] . pointerName )) ()

	In the init(), when assigning the funcPointer to struct member, 
		the name of the function must have the & nad then the class name, without ()
			harl[i].pointerToFunction = &Harl::debug;

	Sometimes the class name Harl:: must be repeated again inside a function, 
		even if the function name already has it ( void Harl::init ) ...
*/

class Harl
{
	public:
		Harl();
		~Harl();

		void complain(std::string level);
	
		typedef struct s_data
		{
			std::string level;
			// function pointer
			void (Harl::*pointerToFunction)(void);

		} t_data;
		
		t_data data[4];

	private:
		void debug();
		void info();
		void warning();
		void aaa();
		void init();
};

void Harl::init()
{
	data[0].level = "debug";
	data[1].level = "info";
	data[2].level = "warning";
	data[3].level = "aaa";

	data[0].pointerToFunction = &Harl::debug; // how to write this
	data[1].pointerToFunction = &Harl::info; // how to write this
	data[2].pointerToFunction = &Harl::warning; // how to write this
	data[3].pointerToFunction = &Harl::aaa; // how to write this
}

Harl::Harl()  // ????
{
	init();
}


Harl::~Harl()
{
}


void Harl::complain(std::string level)
{
	int i {0};

	while (i < 4)
	{
		if (level == data[i].level)
		{
			// call function pointer
		//	harl[i].pointerToFunction(); // ????
			(this->*(data[i].pointerToFunction))(); // ????
		}
		i++;
	}
}

void Harl::debug()
{
	std::cout << "print debug\n";
}
void Harl::info()
{
	std::cout << "print info\n";
}
void Harl::warning()
{
	std::cout << "print warning\n";
}
void Harl::aaa()
{
	std::cout << "print aaa\n";
}

int main()
{
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("aaa");
}
