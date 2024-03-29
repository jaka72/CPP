/* 
	QUESTIONS

	- In what situation would you use a struct inside a class?


	- Shall I use getters and setters always for all private vars??
		Or only when it is necessary?
	
	- Can you put class member functions definitions in more other files, how do you then name those files?
*/


/*
	STRANGE BEHAVIOUR OF FLOAT, LOOSING PRECISION:
	
	If input is a large float, then Int overflow must be checked before casting int 
	into float. because a large float is stored in scient. representation which can 
	be rounded down, therefore it will not be overflow, after casting this float to int.
				float f = 2147483647.0f;
					== 2.14748e+09      stored as float. point representation (printed as scient)   
					== 2147480000	   casted to int (smaller than original)
	So, casting a larger float to int, seems to always give back distorted int ????
	But above a certain value (around 2147483600), cast to int starts giving back INT_MIN -2147483648

	Interestingly, substracting these gives wrong result, zero:
				float f1 = 2147483647.0f;
				float f2 = 2147483648.0f;
				std::cout << "float " << f2 - f1 << "\n";    --->>>   result: 0
*/

/*
// 
// ISSUE IN PRINT FLOATANDDOUBLE: NOW IM PRINTING .0  FOR FLOAT AND DOUBLE AFTER SCIENT. NOTATION,
//  WHEN CONVERTING FROM NEGATIVE INTEGER, LARGER THAN 6 DIGITS !!!
// HERE IT NEEDS TO CHECK IF IT IS NEGATIVE, AND THEN DECIDE WHAT TO SUBSTRACT,
//    		if (_f - (int)_f == 0 && _f < 10000)
// 					OR THE OTHER WAY AROUND

// ISSUE !!!!
*/


/*
	REMARKS
	- atof() automaticaly gives back the 'inf', if it is overflow

	- stoi has issue with -std=c++98, apparently it belongs to c++11

	- stoi throws exception 'stoi' if int overflows and exists. I dont want this.
		I want to print 'impossible' and also print value of float and double
		Therefore I dont want to use stoi()

	- Now I treat space " " as a valid printable char, but
				  "   " I treat as invalid string, just empty spaces,
		Similarly, "a" is valid, "aaaa" is invalid
*/


/*
	MEANING OF 'SCALAR'
		- It is a quantity, which has only magnitude, but no direction.
			(Scalar, representable on a scale).
			(Real numbers, also floats and roots)
			(ie: size, mass, density, time, volume ... also speed ??)
			It is describable by a real number.
			In computers, scalars are integers (maybe also pointers) (contain a single value)
						 non-scalars: arrays, classes, .. what else?)
		
		The other type is a VECTOR. It has magnitude and direction (force and velocity)




	FUNDAMENTAL TYPES VS COMPOUND TYPES
		- Fundamental (also called: built-in types): void, boolean, chars, ints, floats
				- integral:         int, char, bool, short, long
				- floating point:   float, double, long double
				- void:             void
		- Compound (array, struct, class, function, pointers, references ... ? )

	Learncpp 4.6 - Finish reading and clarify, fixed types, 
				- To be defined on architecture, what does it mean exactly?

*/



/*
	TYPE CASTING (TYPE CONVERSION)

	A) Implicit (automatic by compiler)
	
	B) Explicit (manual by programmer)

			b1) With () cast operator (used in C, no compile time checking)

			b2) With <> cast operator (used in C++, has compile time checking)

				- static_cast (ex00)        Most common cast. Converts from one fundam. type to 
											another fundam. type:
											static_cast < new_data_type > (expression); 
											int x = static_cast < int > (y); 

				- reinterpret_cast(ex01)    To store a pointer ???
				
				- dynamic_cast(ex02)        To handle polymorphism. Only used when casting from
											base to derived class
											(at runtime, only for class pointers)
				- const_cast


		(Difference between C-cast() and C++cast <> is, that <> is more strict.
		Will not allow casting pointers of types with different size (like char and int)
					char c   = 65;          // 1-byte data. ASCII of ‘A’
					int *ptr = (int*)&c;    // 4-byte

					char c   = 65;
					int *ptr = static_cast<int>(&c);    // Error
*/


//// floats, last displayable: 99999999999999999999999999999999999999

/*
	Floats start being stored as scientific notation, after 6 digits:
		6 digits
		123456.123   -->> printed as 123457     (rounded 6 to 7, decimals not visible anymore)

		7 digits
		1234567.123  -->> printed as 1.23457e+06



	float f = 1234567.999;  // --->>> 1.23457e +06
//            1234570       // biger than original
	std::cout << "float main: " << f << "\n";
	f = 1234568.999;  // --->>> 1.23457e +06 // biger than original
	std::cout << "float main: " << f << "\n";
	f = 1234571.999;  // --->>> 1.23457e +06 // smaller than original
	std::cout << "float main: " << f << "\n";

*/


/*
	// double f = -99999999999999999999999999.123f;
	// std::cout << " m_float " << f << "\n";
	// std::cout << " m_int " << (int)f << "\n";
	
	//float i1 = nan;   error, unknown word, also -inf, +inff ...
	//float i2 = 1.   ;   // valid
	// float i3 = .0f   ;   // valid
	// float i4 = .1f   ;   // valid
	// float i5 = 0.f   ;   // valid
	// float i6 = 1.f   ;   // valid
	
	// std::cout << "float .0f [" << i3 << "]\n";
	// std::cout << "float .1f [" << i4 << "]\n";
	// std::cout << "float 0.f [" << i5 << "]\n";
	// std::cout << "float 1.f [" << i6 << "]\n";
	

	// std::string s1 = "21474836499";
	// std::string s2 = "9223372036854775807";
	// long double i7 = atof(s2.c_str());
	// std::cout << "int 999... overflow [" << sizeof(i7) << ", " << i7 << " ]\n";
	// std::cout << "MAX INT [" << INT_MAX << "]\n";

	//float f1 = 9223372036854775807.0;
	//float f2 = 9223372036854775807999999999999999999999999999999999.0;
	// float f3 = 99999.9;
	// float f4 = 9999999.9;
	// float f5 = 99999999.9;
	// float f6 = 9999999999999999999999999999999999999999999.9;
	// std::cout << f3 << ", " << f4 << ", " << f5 << ", " << f6  << "\n";

	// float f7 = 2147483646.0f;
	// std::cout << f7 << "\n";

	
	// char c = '\t';

	// if (isprint(c))
	//     std::cout << "yes is print\n";
	// else    
	//     std::cout << "no is not print\n";

	// t_indx indx;
	// indx._i 	 = 0;
	// indx._start = 0;
*/
