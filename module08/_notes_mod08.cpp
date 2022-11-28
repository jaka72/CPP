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