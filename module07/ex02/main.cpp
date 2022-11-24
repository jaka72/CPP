/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/24 16:37:46 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <stdio.h>		// for perror
#include "colors.h"
#include "Array.hpp"



// #define MAX_VAL 750
#define MAX_VAL 5

int main(int, char**)
{
	{
		// TEST FROM THE SUBJECT ////////////////////////
		
		Array <int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		
		std::cout << "Store random values to numbers[] and mirror[]\n";
		
		
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
			std::cout << "   value: " << value << "\n";
		}
		
		//SCOPE
		{
			std::cout << YEL"\nA) Copy array:   tmp = numbers;\n" RES;
			Array<int> tmp = numbers;
			
			std::cout << YEL"\nB) Copy array:   test(tmp);\n" RES;
			Array<int> test(tmp);

		}


		std::cout << YEL"\n\nC) Loop and compare mirror[i] vs numbers[i]\n\n" RES;

		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << "loop i" << i << "\n";
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		

		std::cout << YEL"\nD) TEST ERRORS\n\n" RES;
		
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: Index is negative " << e.what() << '\n';
		}
		
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: Index is MAX_VAL " << e.what() << '\n';
		}


		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		
		delete [] mirror;
	}

	
	
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		std::cout << YEL"\n\n - - - Other tests  - - - - - - - - - - - - - - - \n\n" RES;
		
	{
		std::cout << MAG"\n1) Array with <int> args\n" RES;
		Array <int>A(1);

		std::cout << "A[0]:  " << A[0] << '\n';
		A[0] = 99;
		std::cout << "A[0]:  " << A[0] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		std::cout << MAG"2) Array with <int> args\n" RES;
		Array <int>A(1000);

		std::cout << "A[0]:  " << A[0] << '\n';
		A[0] = 99;
		std::cout << "A[0]:  " << A[0] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	

	{
		std::cout << MAG"\n1) Array with <string> args\n" RES;
		Array <std::string>A(3);

		std::cout << "A[0]:  " << A[0] << '\n';
		A[0] = "cookie";
		A[1] = 97;		// Converts char 'a'to a string ???
        A[2] = "milk";
		std::cout << "A[0]:  " << A[0] << '\n';
		std::cout << "A[1]:  " << A[1] << '\n';
		std::cout << "A[2]:  " << A[2] << '\n';
		std::cout << "Array size: " << A.size() << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	

	{
		std::cout << "? ? ? ? ? ? Array as a pointer ? ? ? ? ? ? \n";
		std::cout << "   How to make a pointer Array ???\n\n";
		// Array <int> *A = new Array<int> (2);  // HOW TO DO THIS
		Array <int> *A = new Array<int>(2);  // HOW TO DO THIS
		std::cout << "Array size: " << A->size() << "\n";

	// 	HOW TO ASSIGN VALUES TO THESE MEMBERS OF A POINTER ARRAY	
		//A[0] = 5;

		//std::cout << "A[0]:  " <<  A[0] << '\n';
		std::cout << "A[0]:  " << &A[0] << '\n';
		delete A;
	}
		std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";



	{
		std::cout << MAG"Check if deep copy:   B = A;\n" RES;
		Array <int> A(3);
		A[0] = 11;
		A[1] = 22;
		A[2] = 33;
		
		Array <int> B;

		std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
		std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";

		

		std::cout << BLU"Copy object A to B via =operator \n" RES;
		B = A;		// _arr in B already had NEW memory, allocated in default constructor
					// therefore it must be set deleted and set to NULL in the =overload

		std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
		std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";

		std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
		std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";

		std::cout << BLU"    Change values in the array A\n" RES;
		A[0] = 77;
		A[1] = 88;
		A[2] = 99;
		std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
		std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";




	{
		std::cout << MAG"Check if deep copy:   B(A);\n" RES;
		std::cout << BLU"Duplicate object A to B using brackets:   Array <int> C(A) \n" RES;
		Array <int> A(3);
		A[0] = 11;
		A[1] = 22;
		A[2] = 33;
		Array <int> B(A); // FOR B, ONLY COPY CONSTRUCTOR IS CALLED, SO IT NEVER GETS THE new MEMORY
						  // THEREFORE YOU CANT DELETE THE B._arr, JUST MUST SET IT TO NULL	
						  // B._arr IS SET TO NULL IN COPY CONSTR., SO IT COMES AS NULL INTO =overload
		
		std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
		std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";
		
		std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
		std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";

		std::cout << BLU"    Change values in the array A\n" RES;
		A[0] = 77;
		A[1] = 88;
		A[2] = 99;
		std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
		std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		


	{
		std::cout << MAG"Check subscript overload\n" RES;
		try
		{
			Array <int> A(3);
			A[0] = 11;
			std::cout << A[77] << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Index is out of range!" << e.what() << '\n';
		}
		
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		


	{
		std::cout << MAG"Check Array with <string> arguments\n" RES;

		Array <std::string> A(3);
		A[0] = "wine";
		A[1] = "beer";
		A[2] = "cola";

		std::cout << "Test subscript: \n";
		std::cout << A[1] << "\n";
	}	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";


		
	{
		std::cout << MAG"Testing   int* a = new int();\n" RES;
		std::cout << MAG"Testing   int* b = new int[10];\n" RES;
		int* a = new int();
		int* b = new int[10]; // MAKING ARRAY b WITH 10 INTS
		std::cout << "    *a: " << *a << "\n";
		std::cout << "    *b: " << *b << "\n";
		
		b[0] = 11;

		std::cout << "     b[0]: " << b[0] << "\n";
		std::cout << "     b[1]: " << b[1] << "\n";
		std::cout << "     b[2]: " << b[2] << "\n";
		
		std::cout << "    &b[0]: " << &b[0] << "\n";
		std::cout << "    &b[1]: " << &b[1] << "\n";
		std::cout << "    &b[2]: " << &b[2] << "\n";
		
		delete a;
		delete[] b;
	} 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	


	{
		std::cout << MAG"Testing   Array object as a pointer\n" RES;

		Array <int> *arr = new Array<int>(5);

		(*arr)[0] = 2;
		std::cout << "     (*arr)[0]: " << (*arr)[0] << "\n";

		
	}



	//system ("leaks a.out");
    return 0;
}









int mainXXXXX()
{   // QUESTIONS ////////////////////////////////////////////

	// WHAT IS THE DIFFERENCE IN COPY CONTRUCTOR IN THESE 2 CASES:  - if in main the array is created as non pointer
	//																- as a pointer
	// 		BECAUSE IN ANY CASE, IN CONSTRUCTOR, MEMORY IS ALLOCATED FOR THE array

	// LOOKS LIKE YOU CANT CALCULATE THE SIZE OF A POINTER ARRAY

	// LOOKS LIKE DESTRUCTOR IS CALLED TWICE, IF A CLASS WITH TEMPLATE ARGS IS CREATED ???
	

		




	{
	 	std::cout << MAG"TEST_temp:  Is _arr always NULL when Array <int> A() \n" RES;
			Array <int> A;
			Array <int> B;
			Array <int> C;
									// _arr THEY ALL HAVE ADDRESSES
			std::cout << BLU "      " << A[0] << "\n" RES;
			// std::cout << BLU "      " << B._arr << "\n" RES;
			// std::cout << BLU "      " << C._arr << "\n\n" RES;

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
		// std::cout << "Test tblaase, comparing if copying goes well \n";
		

		// Array <int> tempA(5);
		// for (int i = 0; i < 5 + 1; i++)
        //         std::cout << "tmp[" << i << "]:\t" << tempA[i] << std::endl;

		// Array <int> tempB; // HOW TO COPY AN EXISTING OBJECT ???
				//	tempB(tempA);  				// ERROR, 'The object doesnt have a call operator()'
				//      VS    					//		LOOKS LIKE ITS NOT POSSIBLE
				// Array <int> tempB(tempA);	// OK


		// OK TEST, changing a value
		Array <int> tempA(3);
		Array <int> tempB(3);
		tempA[0] = 33;
		tempB[0] = 99;
		tempA = tempB;
		
		std::cout << "Value tempA[0] " << tempA[0] << "\n";
		std::cout << "Value tempB[0] " << tempB[0] << "\n";

		int *x = new int;	// Always has first value 73896 ??
		int *a = new int();	// Always has first value 0
		int *b = new int[3];

		std::cout << "      *t: " << *x << "\n";
		std::cout << "      *a: " << *a << "\n";
		std::cout << "       a: " << a << "\n";
		std::cout << "       b: " << b << "\n";
		std::cout << "      *b: " << *b << "\n";
		std::cout << "    b[0]: " << b[0] << "\n";

		delete x;
		delete a;
		delete[] b;
				
	}

	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		std::cout << MAG"Test tblaase, comparing if copying goes well \n" RES;
		
		/*
			Create 2 int arrays with same nr of members - a simple int array 'mirror'
														- the object Array 'numbers'
				Put same random numbers in each array (simple is mirror of int).

			Create a third arrray 'temp': the Array object, with default constr (empty _arr)
				Try to print members - it should error, because the size is 0 == empty

			Copy 'numbers' to 'temp' via =

			Copy 'temp' to a fourth Array 'test'  via  Copy constr
			
			Now the temp and test should have the same values as the initial 'numbers' 
		*/

		Array <int> A (10);
		int *Acopy = new int[10];

		for (int i = 0; i < 10; i++)
		{
			A[i]     = i + 11;
			Acopy[i] = i + 11;
		}

		Array <int> B;
		B = A;
		Array <int> C(B);
		
		for (int i = 0; i < 10; i++)
		{
			std::cout << "\n" << A[i] << " " << B[i] << " " << C[i];
			// if (A[i] == B[i] && A[i] == C[i] && B[i] == C[i])
			if (C[i] == Acopy[i])
				std::cout << " same ";
			else	
				std::cout << " diff ";
		}
		
		delete []Acopy;
	}
	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	{
		std::cout << MAG"Test Template object as a pointer: \n" RES;

		Array <int> arr1(3);
		
		// Array <int> *ptr = new Array <int>(3);
		Array <int> *ptr = new Array <int>(arr1);
		std::cout << " size ptr: " << ptr->size() << "\n";


		//arr1 = *ptr;
		// ptr = &arr1;	// LEAKS
		//*ptr = arr1;

		delete ptr;
	}
	 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	
	//system("leaks a.out");
	return 0;
}
