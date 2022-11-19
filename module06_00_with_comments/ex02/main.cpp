/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 18:09:32 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/06 09:35:58 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>  // for rand()
#include <unistd.h> 	// for sleep


#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include "Base.hpp" //  IF BASE IS FIRST, IT CAUSES CIRCULAR SITUATION, ERROR

/* From https://java2blog.com/get-type-of-object-cpp/

	Terminology for same thing:
		- runtume polymorfism,
		- dynamic dispatch of methods
			= method overriding
			
		(C++ supports runtime polymorphism or 
		dynamic dispatch in form of method overriding.)


	Assigning a reference of child to parent:
		B child;
		A *parent = &child; 


	STRANGE DEFINITION OF typeid():
		The typeid() operator is defined as an operator that is used 
		where the dynamic type of a polymorphic object must be known 
		for static type identification. ???

*/

/*	HEADERS HIERARCHY

		in main: all children headers, no parent
		in parent.hpp:  nothing, no children
		in parent.cpp:  only parent.hpp
		in child.hpp:	only parent.hpp
		in child.cpp:	only child.cpp
*/




// Base *genA()
// {
// 	ret[0] = new A();
	
// }


// WHAT IS ALL THIS ????
/*
	In c98 we can create something similar to 'instanceof()'
		by using  dynamic_cast <new-type> (expression)  
*/


// THIS CAN BE USED TO CAST A CHILD POINTER TO A PARENT, BUT NOT TO CAST A CHILD REFERRENCE
// IN THIS CASE THE dynamic_cast RETURNS AN ADDRESS OR NULL, SO IT CAN BE RETURNED AS BOOL,
// WHICH IS THEN RECOFNIZED IN THE identify() 

template <typename BaseParent, typename DerivedChild>

inline bool instance_of(const DerivedChild *ptr)
{
	const Base *temp = dynamic_cast <const BaseParent*> (ptr);

	if (temp)
		return temp;
	return NULL;
	
	// return dynamic_cast <const BaseParent*> (ptr);
	// return 1;
}




// HERE, FOR REFERRENCE THIS DOES NOT WORK, BECAUSE IN THIS CASE THE dynamic_cast DOES NOT 
// RETURN A BOOLEAN, FOR SOME REASON (BUT WITH A POINTER IT DOES RETURN BOOLEAN)
// SO THIS IS NOT USEFUL FOR CASTING A CHILD REFERRENCE TO THE PARENT.
// BETTER TO USE TRY/CATCH INSIDE THE identify(Base &) 
template <typename Parent, typename Child>

// inline bool instance2_of(const Child& ref)
inline bool instance2_of(const Child&)
{
	// return dynamic_cast<const Base*>(ptr)  !=  nullptr;
	// return dynamic_cast <const Parent&> (&ref)  !=  NULL;		// is it crucial the NULL ???
	//int ret = dynamic_cast <const Parent&> (ref);
	//return  dynamic_cast <const Parent&> (ref);
//	std::cout << "returned from inscanceof1: " << dynamic_cast <const Parent&> (ref) << "/n"; 

	return 1;
}



Base* generate(void)
{
	//Base *ret = NULL;
	
	//usleep(1000000);
    srand(time(0));
    int i = rand() % 3;
	std::cout << "random: " << i << "\n";

	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B());
	if (i == 2)
		return (new C());
	return NULL;
}


void identify(Base* p)
{
	std::cout << "Identify: here it needs to print the actual type of"
				"the object, pointed to by p  "; // A, B or C
	std::cout << p << "\n";			

	if (instance_of <A> (p))
		std::cout << "This object is of class A, address:  " << p << "\n";
	if (instance_of <B> (p))
		std::cout << "This object is of class B\n";
	if (instance_of <C> (p))
		std::cout << "This object is of class C\n";

	// Can be also shorter, just this:   (returns NULL or an address)
	std::cout << " ---- Test: what prints: " << dynamic_cast <A*> (p) << "\n";
}



void identify(Base& p)
{
	std::cout << "Identify: here it needs to print the actual type of"
				"the object, referrenced to by &p   "; // A, B or C
	std::cout << &p << "\n";			


	try
	{
		A &a = dynamic_cast <A&> (p);
		(void)a;	// to silence the Unused variable a
		std::cout << "This object is of class A, address: " << &a << "\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "Do nothing\n";
	}
	
	try
	{
		B &b = dynamic_cast <B&> (p);
		(void)b;	// to silence the Unused variable a
		std::cout << "This object is of class B\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "Do nothing\n";
	}

	try
	{
		C &c = dynamic_cast <C&> (p);
		(void)c;	// to silence the Unused variable a
		std::cout << "This object is of class C\n";
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << '\n';
		std::cout << "Do nothing\n";
	}

	

	///////////////////////////////////////////////////////
	// TEST CATCH SEGFAULT - Cannot be caught by try/catch
	try
	{
		std::cout << "TEST CATCH SEGFAULT \n";
		//int *pointer = NULL;   *pointer = 1;
		// (Segfault will terminate before Catch)

		// TEST, WITHOUT TRY/CATCH
		std::cout << "TEST BAD CASTING \n";
		A &testBadCast = dynamic_cast <A&> (p);   (void)testBadCast;
		// (Bad casting does not compile, unless it's inside try)
		// (But Segfault will terminate before Catch)
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " ... From TEst catch segfault\n";
	}
	////////////////////////////////////////////////////////
}


int main()
{
	{
		Base *b0 = generate();

		//b0->_dummy = 123;

		identify(b0);

		Base &ref1 = *b0;
		identify(ref1); 
		
		// A sda;
		// Base &ref2 = sda;
		// identify(sda); 

	}
		std::cout << " - - - - - - - - - - - - - - - - - - - -\n\n\n";

	return 0;
}
