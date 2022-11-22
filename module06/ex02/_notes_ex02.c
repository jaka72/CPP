

/*
	TO DO

	Change cout to cerr everywhere if printing errors!

*/



/*
	In ex02 it should print the type of the object (class name, parent or child).
	This could be done with the function typeid(), but its header <typeinfo>
	is forbidden.
	
	Therefore we solve it without typeid().
	We use 2 versions of the function identify(): 	- for pointers,
													- for referrences.


	Terminology:
	DYNAMIC TYPE VS STATIC TYPE (when talking about POLYMORFIC OBJECT)
	??? Where did I get this ?

			struct parent { virtual ~B() {} }; // polymorphic type
			struct child : parent {};          // polymorphic type
			
			Child   child; 			// most-derived object
			Parent* ptr = &child;
			
					// the static  type of (*ptr) is Parent
					// the dynamic type of (*ptr) is Child

	POLYMORFIC OBJECT
		If it has at least 1 virtual function.
		If object is derived from parent, but parent has no virtual function,
		then they are not polymorfic.


	THE NEED FOR DYNAMIC CASTING:
		When you have a pointer to Base object, which holds allocated a Derived object. And then you 
		want to access a variable in the Derived object, ie:
			Base* b( getObject(true) );        (  getObject() returns new Derived(33, "Apple")  )
		So, I have no direct access to a variable in the Derived, but only to the Base object.
*/


/*
	Found here: www.tutorialspoint.com/cplusplus-equivalent-of-instanceof
	This syntax can be used to cast a child pointer to a parent
	(but not to cast a child referrence, because in case if failure it throws an exception). 
		casting child pointer to parent (upcasting):
			Base* b1 = dynamic_cast <Base> (child_ptr)
		In this case, the dynamic_cast returns an address or NULL, so it can be returned as
		bool, which is then recognized in the indentify().
*/



/*	HEADERS HIERARCHY

		in main: all children headers, no parent
		in parent.hpp:  nothing, no children
		in parent.cpp:  only parent.hpp
		in child.hpp:	only parent.hpp
		in child.cpp:	only child.cpp
*/




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



/*
	In c98 we can create something similar to 'instanceof()'
		by using  dynamic_cast <new-type> (expression)  
*/




/*
Inside <  >  is defined in the template of function instanceOf():
				inside <  > should be the Base/Parent
   But when instanceOf() is called, you put <A> the Child in there.
   This is ok, because the Child is derived from the Parent.
Inside ( ptrChild ) is a pointer to generated object of type A,B,C
So, the casting is kind of trying to see if they both match:
			dynamic cast < A > ( p )     --> is p also A?
			If p is A, then it returns the address of (ptr), otherwise returns NULL
*/


// This dynamic cast is trying to cast a given argument (pointer) to the Base class.
// So, casting a child to its parent (upcasting).

// WITHOUT ANY TEMPLATE - not usable
inline bool myInstanceOf(const Base* ptrChild)
{
	const Base *temp = dynamic_cast <const Base*> (ptrChild);		// Does not work, because it always returns some address. never NULL

	std::cout << BLU"   instanceOf, temp: " << temp << ",  ptr: " << ptrChild << "\n" RES;
	return temp;	
//  return ( dynamic_cast <const Base*> (ptr) );
}



// a) VIA A TEMPLATE, 2 parameters
template <typename T, typename U>

inline bool myInstanceOf(const U* ptrChild)
{
	const Base *temp = dynamic_cast <const T*> (ptrChild);

	std::cout << BLU"   a) instanceOf, temp: " << temp << ",  ptr: " << ptrChild << "\n" RES;
	return temp;	
//  return ( dynamic_cast <const BaseParent*> (ptr) );
}


// b) VIA A TEMPLATE, 1 parameter
template <typename T>

inline bool myInstanceOf(const Base* ptrChild)
{
	const Base *temp = dynamic_cast <const T*> (ptrChild);

	std::cout << BLU"   b) instanceOf, temp: " << temp << ",  ptr: " << ptrChild << "\n" RES;
	return temp;	
//  return ( dynamic_cast <const BaseParent*> (ptr) );
}

