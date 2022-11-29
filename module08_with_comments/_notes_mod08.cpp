/*
	- How is this declaration explained?
	- Why is throw() at the end?
			virtual const char *what() const throw();



	How to use the std::iterator ???
		It is only working with template T
		But how to use it with a specific type, int or unsigned int ???


	In mod08/02_vector 
		How to correctly write overload= definition in the .tpp or .cpp file
		Now it is only working in the .hpp file
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
		- 1. Container classes:  	list, stack, vector, array ...
		- 2. Algorithms:			sort ???
		- 3. Iterators:
	
	But, when in cppReference, there are same names listed as Libraries, and many more:
		- Containers library, Ranges libr., Iterators libr., ...
		DO THEY MEAN THE SAME THING?
		Is the Container library, listed under Standard Library, the same as the Containers
		under Template Library??

		If you look at the group of c++ headers before C11, there are all these:
			<iostream>, <vector>, <deque> ... <algorithm> <iterator>
*/


/*		STANDARD LIBRARY PARTS
			1. STANDARD FUNCTION LIBRARY: I/O, strings, time, allocation ... ???

			2. OBJECT ORIENTED CLASS LIBRARY: 	- I/O classes, string class, 
												- STL: 	- containers
														- iterators
														- algorithms ...

			THE ABOVE 2 GROUPS ARE NOT THE SAME IN THE cppPreference.com
			THERE ARE MORE LIBRARIES UNDER THE STANDARD LIBRARY:
					- strings lbr:			<string> <string_view>
					- input/output lbr:		<ios> <iostream> ...
					- general utilities lbr. ...
					- diagnostic lbr:		<cerrno> <exception>
					- time lbr				<chrono> ...
					- numerics lbr:			<cmath> <numeric> ...

			In cppPreference many headers are in one group, C++ LIBRARY HEADERS:
				<iostream> <string> <vector> <stack> ...
				<iterator> <algorithm>
				But there is no header <containers>


			There seems to be a difference between 2 groups of headers:
			a) C++ library headers:
					<iostream> <string> <vector> <stack> ... <iterator> <algorithm>
			b) C++ headers for C library facilities
					<ctime> <cstring> <cmath> <climits> <cerrno>
*/


/*	WHAT ARE ITERATORS EXACTLY ???
	
	a) There seem to be another library called ITERATORS, next to the library CONTAINERS
		but
	b) In the container Vector, there is a group of member functions, 
		called Iterators: begin(), end(), cend() ...

		SO, NOT SURE IF a) and b) ARE THE SAME THING

	
	ALL CONTAINERS PROVIDE AT LEAST 2 ITERATORS:	::iterator
													::const_iterator

	DECLARING THE ITERATOR, BY USING THE CONTAINERS OWN ITERATOR:
		std::vector<int>::iterator it;
		it = vect.begin();				// assign it to the start of container


	THE KEYWORD typename MUST BE PRESENT, WHEN USED INSIDE OF A TEMPLATE
		a) typename T::iterator 		easyfind(T& arr, const int n)
		b) std::vector<int>::iterator 	it = ...


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
