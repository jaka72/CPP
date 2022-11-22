

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
	TO DO

	Change cout to cerr everywhere if printing errors!

*/