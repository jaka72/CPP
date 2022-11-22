/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/22 15:51:09 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>		// for rand()
#include <unistd.h>		// for sleep
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	std::cout << GRE"Generated random nr: " << i << "\n" RES;

	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else if (i == 2)
		return (new C());
	return NULL;
}



template <typename T>

inline bool myInstanceOf(const Base* ptrChild)
{
	const Base *ret = dynamic_cast <const T*> (ptrChild);

	std::cout << GRE"   myInstanceOf: ret " << ret << ",  ptr " << ptrChild << "\n" RES;
	return ret;	
//  return ( dynamic_cast <const BaseParent*> (ptr) );
}



// The dynamic_cast does not work for referrence, because
// it doesn't return Beoolean. Better way is
// to use try/catch block inside the identify(Base &) 



// DETECTING A POINTER:   ie: Base *p = generate()   returns a child A,B,C of parent Base
void identify(Base* p)
{
	std::cout << BLU"Called identify pointer Base * p\n" RES"Identify the actual type of "
				 "the object, pointed to by *p " << p << "\n";	// A, B or C

	if (myInstanceOf <A>(p))
		std::cout << GRN"   This object is of class A, address:  " << p << "\n" RES;
	if (myInstanceOf <B>(p))
		std::cout << GRN"   This object is of class B, address:  " << p << "\n" RES;
	if (myInstanceOf <C>(p))
		std::cout << GRN"   This object is of class C, address:  " << p << "\n" RES;
}



// DETECTING A REFERRENCE:   ie: Base *p = generate()
void identify(Base& p)
{
	std::cout << BLU"Called identify referrence Base & p\n" RES"Identify the actual type of "
				 "the object, referrenced to by &p " << &p << "\n";	// A, B or C

	try
	{
		Base &a = dynamic_cast <A&> (p);
		std::cout << GRN"   This object is of class A, address: " << &a << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << GRE"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
	}
	
	try
	{
		Base &b = dynamic_cast <B&> (p);
		std::cout << GRN"   This object is of class B, address: " << &b << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << GRE"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
	}

	try
	{
		Base &c = dynamic_cast <C&> (p);
		std::cout << GRN"   This object is of class C, address: " << &c << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << GRE"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
	}
}





int main()
{
	{
		std::cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n" RES;
		std::cout << BLU"TEST: Pointers, detect the correct type - - - - - - - - - - -\n\n" RES;

		Base *ptr = generate();
		std::cout << GRE"Address of generated object: " << ptr << "\n" RES;

		identify(ptr);
		std::cout << "   ~ ~ ~ \n";
		identify(*ptr);
		delete ptr;
	}


	{
		std::cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n" RES;
		std::cout << BLU"TEST: Referrence, detect the correct type - - - - - - - - - -\n\n" RES;

		Base *ptr = generate();
		Base &ref = *ptr;
		std::cout << GRE"Pointer    to generated object: " << ptr  << "\n" RES;
		std::cout << GRE"Referrence to generated object: " << &ref << "\n" RES;
		
		identify(ref);
		std::cout << "   ~ ~ ~ \n";
		identify(&ref);
		delete ptr;
	}
}
