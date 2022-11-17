

/*
	STILL TO DO:
	- check if besigned and signfrom is everywhere repaired
	- remove setgrade from everywhere

	- maybe try also creating bureacurats as pointers, as an example in all excercises

	- clarify, why is virtual and where?  
		- In child header, parent name after child class, ie:  class child : virtual public parent
		- In parent header, function declaration, as pure virtual = 0 . , it has no definition in the parent, only later in children
		- In parent header, a virtual destructor (if there are children)

		In parent or child, if function is originaly member of Exception, should it be declared virtual???
				ie:  virtual const char *what() const throw();   ????
		- etc ... ???
*/


/*
	Attaching suffix _copy to a copy:
		Apparently only possible in Copy constructor  Bureaucrat br2(br1)
		But not in overload=    br3 = br2
		(because in overload you cant use init.list  :      )
		(you can use it only in constructors)
		(so, the _name cannot be changed in overload= ,if it is a const) 


		Differences in copy(src)  vs   cpy = src
		Three variants:			a)	Bureaucrat br2(br1);		copy constr
								b)	Bureaucrat br3 = br2;		copy constr
								c)	Bureaucrat br3;				default +_ overload=
										br3 = br2;
	
	You can do the throw anywhere in the code. It does not have to be in the try block.
	After throw you need to provide something (int, string, class ...)
		throw 1,    throw "some msg",   throw SomeClass
	
	If you wanna throw a class, it can be declared inside another class (ie: class Form
	will create an object Form, but if you try to create it with invalid args, it throws an
	exception. And this exception can be another class, declared inside the Form class.)
	(You can also add custom constructors for your exception class, ie: a constructor with
	a string as a parameter.)
	
	If you wanna throw a class , it can be with or without argm:
		throw SomeClass();						--> calls default constr.
		throw SomeClass("some string", ...);	--> calls param constr.

	In case of class throw, the class must have the brackets:  throw SomeClass()
	This calls the class contructor. In this constructor, you can add other things, 
	like printing something.
		 
	If you put a string in the class throw (ie: throw SomeClass("some string"), you can imm. 
	print it in the constructor of this class.


	Regarding what(), apparently the default practice is, that you put a message in the what.
	So it will alwaysprint the same message. Only then you can add extra message, for example in the
	contructor of the child class of Exception parent.

*/

