/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/20 18:18:06 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>		// for rand()
#include <unistd.h>		// for sleep
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include "Base.hpp" //  IF BASE IS FIRST, IT CAUSES CIRCULAR SITUATION, ERROR




// Found here: www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
// THIS CAN BE USED TO CAST A CHILD POINTER TO A PARENT, BUT NOT TO CAST A CHILD REFERRENCE
// IN THIS CASE THE dynamic_cast RETURNS AN ADDRESS OR NULL, SO IT CAN BE RETURNED AS BOOL,
// WHICH IS THEN RECOGNIZED IN THE identify() 

// This dynamic cast is trying to cast a given argument (pointer) to the Base class.
// So, casting a child to its parent.
template <typename BaseParent, typename DerivedChild>

inline bool myInstanceOf(const DerivedChild *ptr)
{
	const Base *temp = dynamic_cast <const BaseParent*> (ptr);

	std::cout << BLU"   instanceOf, temp: " << temp << ",  ptr: " << ptr << "\n" RES;

	return temp;	
//  return ( dynamic_cast <const BaseParent*> (ptr) );
}




// HERE, FOR REFERRENCE THIS DOES NOT WORK, BECAUSE IN THIS CASE THE dynamic_cast DOES NOT 
// RETURN A BOOLEAN, FOR SOME REASON (BUT WITH A POINTER IT DOES RETURN BOOLEAN)
// SO THIS IS NOT USEFUL FOR CASTING A CHILD REFERRENCE TO THE PARENT.
// BETTER TO USE TRY/CATCH INSIDE THE identify(Base &) 
template <typename Parent, typename Child>

inline bool myInstanceOf2(const Child&)
{
	// SUCH CAST DOESNT WORK WITH REFERRENCES
	// return dynamic_cast<const Base*>(ptr)  !=  nullptr;
	return 1;
}



Base* generate(void)
{
	srand(time(0));
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



// DETECTING A POINTER:   ie: Base *p = generate()   returns a child A,B,C of parent Base
// Inside <  >  is defined in the template of function instanceOf():
//				inside <  > should be the Base/Parent
//    But when instanceOf() is called, you put <A> the Child in there.
//    This is ok, because the Child is derived from the Parent.
// Inside (  ) is a pointer to generated object of type A,B,C
// So, the casting is kind of trying to see if they both match:
//			dynamic cast < A > ( p )     --> is p also A?
// 			If p is A, then it returns the address of (ptr), otherwise returns NULL
void identify(Base* p)
{
	std::cout << "Called identify Base * p\n";
	std::cout << "Identify the actual type of "
				 "the object, pointed to by *p "; // A, B or C
	std::cout << p << "\n";			

	if (myInstanceOf <A> (p))
		std::cout << "   This object is of class A, address:  " << p << "\n";
	if (myInstanceOf <B> (p))
		std::cout << "   This object is of class B, address:  " << p << "\n";
	if (myInstanceOf <C> (p))
		std::cout << "   This object is of class C, address:  " << p << "\n";
}




// DETECTING A REFERRENCE:   ie: Base *p = generate()
void identify(Base& p)
{
	std::cout << "Called identify Base & p\n";
	std::cout << "Identify the actual type of "
				"the object, referrenced to by &p "; // A, B or C
	std::cout << &p << "\n";			


	try
	{
		// A &a = dynamic_cast <A&> (p);
		Base &a = dynamic_cast <A&> (p);
		std::cout << "   This object is of class A, address: " << &a << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << BLU"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
	}
	
	try
	{
		Base &b = dynamic_cast <B&> (p);
		std::cout << "   This object is of class B, address: " << &b << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << BLU"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
	}

	try
	{
		Base &c = dynamic_cast <C&> (p);
		std::cout << "   This object is of class C, address: " << &c << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << BLU"   Exception, the 2 types don't match:  " << e.what() << "\n" RES;
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
