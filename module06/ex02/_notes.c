

/*

	Change cout to cerr everywhere if printing errors!

	In ex04 it should print the type of the object (class name, parent or child).
	This could be done with the function typeid(), but its header <typeinfo>
	is forbidden.
	
	Therefore we solve it without typeid().
	We use 2 versions of the function identify. One is for pointers, and the
	other for referrences.


	Terminology:
	DYNAMIC TYPE VS STATIC TYPE (when talking about POLYMORFIC OBJECT)

			struct parent { virtual ~B() {} }; // polymorphic type
			struct child: parent {};           // polymorphic type
			
			Child   child; 			// most-derived object
			Parent* ptr = &child;
			
					// the static  type of (*ptr) is Parent
					// the dynamic type of (*ptr) is Child

	POLYMORFIC OBJECT
		If it has at least 1 virtual function.
		If object is derived from parent, but parent has no virtual function,
		then they are not polymorfic.

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
