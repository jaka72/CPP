/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/11 12:31:15 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>		// for perror
#include "colors.h"

template <typename T>
class Array
{
	private:

	public:
		// SHOULD PROBABLY GO TO PRIVATE
		T               *_arr;
		unsigned int    _size;
		
		// 1)
		Array() : _size(0)	// create array with 0 size. So size gets a value already now
		{
			std::cout << GRE"Constructor Array\n" RES;
			_arr = new T[0];
		};
		
		// 2)
		Array(unsigned int n)	: _size(n)
		{
			std::cout << GRE"Param constructor Array\n" RES;
			_arr = new T[_size];
			
			_arr[0] = 11;	// temp, for testing
			_arr[1] = 22;	// temp, for testing
		};
		
		~Array()
		{
			std::cout << GRE"Destructor\n" RES;
			std::cout << "    arr[0]:  " << _arr[0] << "\n";

			if (_arr != NULL)	// ADDED FROM TBLASE, WHERE WOULD_arr BE SET TO NULL ??
				delete []_arr;
		}
		
		// 7)
		unsigned int size() const
		{
			return (this->_size);
		}


		// 3) A    Copy constructor - must be deep copy!
		Array(const Array &src)
		{
			std::cout << GRE"Copy constructor called\n" RES;
			std::cout << GRE"   (THE COPY HAS NO new ALLOCATED MEMORY YET, SO YOU CANT DELETE IT HERE, JUST SET TO NULL)\n" RES;
			std::cout << GRN"       what is src._arr at this point: " << src._arr << "\n" RES;
			std::cout << GRN"       what is arr at this point:      " << this->_arr << "\n" RES;
			std::cout << BLU"       what is src[0] at this point:   " << src._arr[0] << "\n" RES;
			std::cout << BLU"       what is arr[0] at this point:   " << this->_arr[0] << " (random value)\n" RES;

			// here not needed checking if its the same???  -->  if (this == &src) ...
			// 		Apparently not, because this check is already in =overload, so it
			//		happens there.
						
			// THE COPY HAS NO new ALLOCATED MEMORY YET, SO YOU CANT DELETE IT HERE, JUST SET TO NULL
			// if (this->_arr != NULL)		// !!! THIS PREVENTS LEAKS WHEN A = B
			// {							// BUT NOW B(A) GIVES DOUBLE FREE
			// 	std::cout << LRD"       _arr IS NOT NULL, NOW delete []_arr\n" RES;
			// 	delete []_arr;
			// }		
					

			// setting _arr to NULL, because now it is garbage 	
			std::cout << GRE"     Setting this->_arr to NULL\n" RES;
			this->_arr = NULL;	// !!! THIS IS CRUCIAL, TO PREVENT LEAKS OR DOUBLE FREE

			*this = src;		//			WHEN A = B    or   B(A)		!!!
			// here above the =overload already happened, so the duplicate already has different addresses
			
			// NOW THE _arr HAS SAME COPIED VALUES, BUT AT DIFFERENT ADDRESSES: 
			std::cout << BLU"       what is src[0] at this point: " <<   src._arr << "\n" RES;
			std::cout << BLU"       what is arr[0] at this point: " << this->_arr << "\n" RES;
			std::cout << GRN"       what is src[0] at this point: " <<   src._arr[0] << "\n" RES;
			std::cout << GRN"       what is arr[0] at this point: " << this->_arr[0] << "\n" RES;
		}



		// 3) B    Assignment operator= overload
		Array &operator= (const Array &src)
		{
			std::cout << GRE"Assignment operator= overload\n" RES;
			std::cout << GRN"       what is src at this point:    " << src._arr << "\n" RES;
			std::cout << GRN"       what is arr at this point:    " << _arr << "\n" RES;
			if (this == &src)
				return (*this);

			std::cout << GRN"       Is this->_arr == NULL? " << this->_arr << "\n" RES;
			if (this->_arr == NULL)	
				std::cout << GRE"       _arr IS NULL!\n" RES;
			if (this->_arr != NULL)		// !!! THIS PREVENTS LEAKS WHEN A = B
			{							// BUT NOW B(A) GIVES DOUBLE FREE
				std::cout << LRD"       _arr IS NOT NULL, NOW delete []_arr\n" RES;
				delete []_arr;
			}		
			std::cout << GRN"       Is this->_arr == NULL? " << this->_arr << "\n" RES;
				
			
			this->_size = src._size;

			// copy whole array
			unsigned int i = 0;
			_arr = new T[_size]; 	// THIS IS CAUSING LEAK IN CASE A = B . ,WHERE THEN DOES THE MEMORY FOR THE NEW ARRAY COME FROM ???
									//   BUT WITHOUT THIS IS CAUSING DOUBLE FREE IN B(A)     ???
			std::cout << GRN"       Is this->_arr == NULL? After new: " << this->_arr << "\n" RES;

			if (_arr == NULL)
			{
				// WHY 2 DIFFERENT ERROR MESSAGE VARIANTS ?
				// NOT SURE IF GOOD TO EXIT? BECAUSE THE OBJECT MAY NOT DESTRUCT!
				perror("memory allocation for Array _arr failed\n");
				std::cerr << "memory allocation for Array _arr failed\n";
			}
			
			// NOT SURE, THIS WE DID SO IN THE ANIMAL-BRAIN, BUT BRAIN WAS A CLASS OBJECT THERE
			// *this->_arr = *src._arr; // ????? THIS DOES NOT MAKE ANY DIFFERENCE, STILL 1 LEAK!

			std::cerr << GRE"   Copying array:\n" RES;
			while (i < _size)
			{
				this->_arr[i] = src._arr[i];
				std::cout << GRE"       while arr[i] = " << _arr[i] << "\n" RES;
				i++; 
			}
			return (*this);
		}

		// 5)
		// subscript operator[] overload, with catching exception when out of bounds
		T &operator[] (unsigned int i)
		{
			try
			{
				if (i < 0 || i >= _size || _arr == NULL)  // WHEN SI THIS SET TO NULL ?
				{
					std::cout << "   Error, index is out of range!\n";
					throw "   Throw: Error, index is out of range!\n";
				}
			}
			catch(const char* str)
			{
				std::cout << str;
			}
			catch(const std::exception& e) // Is this needed ???
			{
				std::cerr << e.what() << '\n';
			}
			return (_arr[i]);
		}
};




int main()
{   // QUESTIONS ////////////////////////////////////////////

	// WHAT IS THE DIFFERENCE IN COPY CONTRUCTOR IN THESE 2 CASES:  - if in main the array is created as non pointer
	//																- as a pointer
	// 		BECAUSE IN ANY CASE, IN CONSTRUCTOR, MEMORY IS ALLOCATED FOR THE array

	// LOOKS LIKE YOU CANT CALCULATE THE SIZE OF A POINTER ARRAY

	// LOOKS LIKE DESTRUCTOR IS CALLED TWICE, IF A CLASS WITH TEMPLATE ARGS IS CREATED ???
	
	{
		std::cout << MAG"1) Array as a non-pointer. with <int> args\n" RES;
		Array <int>A(1);

		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		A._arr[0] = 11;
		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		
	{
		std::cout << MAG"2) Array as a non-pointer. with <int> args\n" RES;
		Array <int>A(1000);

		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		A._arr[0] = 11;
		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		
	{
		Array <std::string>A(2);

		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		A._arr[0] = "cookie";
		A._arr[1] = 97; 	// ?? Converts to char 'a' . but should be a string
//      A._arr[2] = 3.3;	// error, conversion from float to char
		std::cout << "A._arr[0]:  " << A._arr[0] << '\n';
		std::cout << "A._arr[1]:  " << A._arr[1] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		//std::cout << "Array as a pointer - error, cannot deduce class template arguments\n";
		// Array *A = new Array <int>(12);  // HOW TO DO THIS
	}
		// std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		std::cout << MAG"Check if deep copy:   B = A;\n" RES;
		Array <int> A(3);
		Array <int> B;

		std::cout << BLU"Duplicate object A to B using operator= overload\n" RES;
		B = A;		// B._arr ALREADY HAS ADDRESS, BEFORE CALLING B=A, 
					// THEREFORE IT NEEDS TO BE SET TO NULL IN =overload
		
		std::cout << "    A.size:  " << A._size << ",  B.size:   " << B._size << "\n";
		std::cout << "   &A.size: " << &A._size << ",  &B.size: " << &B._size << "\n\n";	// error, freed pointer not allocated ????
		
		
		// Cheking that addresses are different in orig and duplicate
		std::cout << "    A.arr[0]:  " << A._arr[0] << ",    B.arr[0]:   " << B._arr[0] << "\n";
		std::cout << " . &A.arr[0]:  " << &A._arr[0] << ",  &B.arr[0]:   " << &B._arr[0] << "\n\n";


		// Modifiy arr[] inside Array - it must not affect his duplicate
		A._arr[0] = 123;
		B._arr[0] = 456;
		std::cout << "    A.arr[0]:  " << A._arr[0] << ",    B.arr[0]:   " << B._arr[0] << "\n";
		std::cout << "   &A.arr[0]:  " << &A._arr[0] << ",  &B.arr[0]:   " << &B._arr[0] << "\n\n";
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	

	{
		std::cout << MAG"Check if deep copy:   B(A);\n" RES;
		std::cout << BLU"Duplicate object A to B using brackets:   Array <int> C(A) \n" RES;
		Array <int> A(3);
		Array <int> B(A); // FOR A, NO CONSTRUCTOR IS CALLED, SO IT NEVER GETS THE new
						  // THEREFORE YOU CANT DELETE THE _arr, JUST MUST SET TO NULL	
						  // B._arr IS SET TO NULL IN COPY CONSTR., SO IT COMES AS NULL INTO =overload
		
		std::cout << "   A.size:  " << A._size << ",  B.size:   " << B._size << "\n";
		std::cout << "   &A.size: " << &A._size << ",  &B.size: " << &B._size << "\n\n";	// error, freed pointer not allocated ????
		
		
		// Cheking that addresses are different in orig and duplicate
		std::cout << "    A.arr[0]:  " << A._arr[0] << ",    B.arr[0]:   " << B._arr[0] << "\n";
		std::cout << " . &A.arr[0]:  " << &A._arr[0] << ",  &B.arr[0]:   " << &B._arr[0] << "\n\n";


		// Modifiy arr[] inside Array - it must not affect his duplicate
		A._arr[0] = 123;
		B._arr[0] = 456;
		std::cout << "    A.arr[0]:  " << A._arr[0] << ",    B.arr[0]:   " << B._arr[0] << "\n";
		std::cout << "   &A.arr[0]:  " << &A._arr[0] << ",  &B.arr[0]:   " << &B._arr[0] << "\n\n";

	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	// {
	// 	std::cout << MAG"Check subscript overload\n" RES;

	// 	Array <int> A(3);
	// 	A._arr[0] = 11;

	// 	std::cout << "   Test subscript: \n";
	// 	std::cout << A[77] << "\n";
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		
	// {
	// 	std::cout << MAG"Testing   int* a = new int();\n" RES;

	// 	int* a = new int();
		
	// 	std::cout << "    *a: " << *a << "\n";

	// 	delete a;
	// }


		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	// {
	// 	std::cout << MAG"Check Array with <string> arguments\n" RES;

	// 	Array <std::string> A(3);
	// 	A._arr[0] = "wine";
	// 	A._arr[1] = "beer";
	// 	A._arr[2] = "cola";

	// 	std::cout << "   Test subscript: \n";
	// 	std::cout << A[1] << "\n";
	// }
	// 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		
	// {
	// 	std::cout << MAG"Testing   int* a = new int();\n" RES;
	// 	std::cout << MAG"Testing   int* b = new int[10];\n" RES;
	// 	int* a = new int();
	// 	int* b = new int[10]; // MAKING ARRAY b WITH 10 INTS
	// 	std::cout << "    *a: " << *a << "\n";
	// 	std::cout << "    *b: " << *b << "\n";
		
	// 	b[0] = 11;

	// 	std::cout << "     b[0]: " << b[0] << "\n";
	// 	std::cout << "     b[1]: " << b[1] << "\n";
	// 	std::cout << "     b[2]: " << b[2] << "\n";
		
	// 	std::cout << "    &b[0]: " << &b[0] << "\n";
	// 	std::cout << "    &b[1]: " << &b[1] << "\n";
	// 	std::cout << "    &b[2]: " << &b[2] << "\n";
	// 	delete a;
	// }

	{
	 	std::cout << "TEST_temp:  Is _arr always NULL when Array <int> A() \n";
			Array <int> A;
			Array <int> B;
			Array <int> C;
									// _arr THEY ALL HAVE ADDRESSES
			std::cout << BLU "      " << A._arr << "\n" RES;
			std::cout << BLU "      " << B._arr << "\n" RES;
			std::cout << BLU "      " << C._arr << "\n\n" RES;

			std::cout << "* * * * * * * * * * \n\n";

			Array <int> D(3);
			Array <int> F(D); // NO new _arr IS ALLOCATED FOR F, BUT
							  //  THE COPY CONSTR IS CALLED IMMEDIATELY
							  //  SO IT MUST SET _arr TO NULL, BECAUSE IT
							  //   WILL BE CHECKED AND DELETED IN =overload
							  //   IF THE TARGET HAS PREVIOUSLY MEMORY ALLOCATED
	}
	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		std::cout << "Test tblaase, comparing if copying goes well \n";
		
		CONTINUE HERE
		/*
			Create 2 int arrays with same nr of members - a simple int array 'mirror'
														- the object Array 'numbers'
				Put same random numbers in each array (simple is mirror of int).

			Create a third arrray 'temp': the Array object, with default constr (empty _arr)
				Try to print members - it should error, because the size is 0 == empty

			Copy 'numbers' to 'temp' via =

			Copy 'temp' to a fourth Array 'test'  via  Copy constr
			
			Now the temp and test should have the same vaues as the initial 'numbers' 
		*/
	
		Array <int> temp;
		for (int i = 0; i < 5 + 1; i++)
                std::cout << "tmp[" << i << "]:\t" << temp[i] << std::endl;
	}

	// system("leaks a.out");
	return 0;
}
