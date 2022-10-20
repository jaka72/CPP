#include <iostream>
#include <string>

class Animal // This Animal is an abstract base class
{
	protected:
		std::string m_name;
	
	public:

		Animal()
		{};
		Animal(const std::string& name)
			: m_name{ name }
		{ }
		
		const std::string& getName() const { return m_name; }
	
		virtual const char* speak() const = 0; // note that speak is now a pure virtual function

		virtual ~Animal() = default;
};


class Cow: public Animal
{
	public:
		Cow(const std::string& name) : Animal(name)
		{  	}

		// const char* speak() const override { return "Moo"; }
		const char* speak() const            { return "Moo"; }
};

int main()
{
	// Animal anm2("jaja");


    Cow cow{ "Betsy" };
    std::cout << cow.getName() << " says " << cow.speak() << '\n';

//	Animal anm1;		// not possible, it is abstract class
//	Animal anm1(cow);	// not possible, it is abstract class

	Animal& anm2(cow);	// OK   as reference to Cow
  
	Animal* anm3(&cow);	// OK	as pointer to Cow
  
  
    std::cout <<  anm2.getName() << " says " <<  anm2.speak() << '\n';	// same as cow.speak()
    std::cout << anm3->getName() << " says " << anm3->speak() << '\n';  // same as cow.speak()

    return 0;
}