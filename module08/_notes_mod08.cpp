/*
	- How is this declaration explained?
	- Why is throw() at the end?
			virtual const char *what() const throw();



	How to use the std::iterator ???
		It is only working with template T
		But how to use it with a specific type, int or unsigned int ???
*/


/*
	There is new stuff about std::initializer list, to read and test:
		learncpp_16.7 
*/

/*
	Looks like people are using #include <array>	
		But  warning on Linux:	‘std::array’ is only available from C++11 onwards


*/


/*		- - - STL, THE STANDARD TEMPLATE LIBRARY - - -
	
	It provides common data structures and functions:
		- Container classes:  	list, stack, vector, array ...
		- Algorithms:			sort ???
		- Iterators:
*/


/*				- - - CONTAINERS - - -

	SEQUENCE CONTAINERS			ADAPTOR CONTAINERS			ASSOCIATIVE CONTAINERS
	vector, deque, list			stack, ...					set, map ...
	( array C11 )
*/




/*
	ABOUT CONTAINER 'THE STACK'

	It has member functions:	top()  empty()	size()	push()	pop()
								( swap C11 )

	Container c  !!!
	Is the underlying container. It is a protected member object of Stack
*/

/*
	Creating a templated object from class:
		Class definition needs a template line:		template <typename T, typename U>
													class ABC { }

		Then, when creating the object, you need to put <argument list> after the object name.
		This arg list must correspond to the types after the object name( i, f )
					ABC<int, float>  		abc1(i, f);		
					ABC<char, int> 			abc('x', 33);		// creating object with 2 args (char, int)
					ABC<int, std::string> 	abc(22, "milk");
   					ABC<float, double> 		abc(2.25, 3.33);
					... etc
*/
