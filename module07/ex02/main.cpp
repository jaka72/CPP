/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 18:05:21 by jaka          #+#    #+#                 */
/*   Updated: 2022/11/25 11:02:41 by jmurovec      ########   odam.nl         */
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
			//std::cout << "   value: " << value << "\n";
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
			//std::cout << "loop i" << i << "\n";
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
		
	// {
	// 	std::cout << MAG"\n1) Array with <int> args\n" RES;
	// 	Array <int>A(1);

	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	A[0] = 99;
	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	std::cout << "Array size: " << A.size() << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";


	// {
	// 	std::cout << MAG"2) Array with <int> args\n" RES;
	// 	Array <int>A(1000);

	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	A[0] = 99;
	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	std::cout << "Array size: " << A.size() << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	

	// {
	// 	std::cout << MAG"\n1) Array with <string> args\n" RES;
	// 	Array <std::string>A(3);

	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	A[0] = "cookie";
	// 	A[1] = 97;		// Converts char 'a'to a string ???
    //     A[2] = "milk";
	// 	std::cout << "A[0]:  " << A[0] << '\n';
	// 	std::cout << "A[1]:  " << A[1] << '\n';
	// 	std::cout << "A[2]:  " << A[2] << '\n';
	// 	std::cout << "Array size: " << A.size() << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";

	

	// {
	// 	std::cout << MAG"Check if deep copy:   B = A;\n" RES;
	// 	Array <int> A(3);
	// 	A[0] = 11;
	// 	A[1] = 22;
	// 	A[2] = 33;
		
	// 	Array <int> B;

	// 	std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
	// 	std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";

		

	// 	std::cout << BLU"Copy object A to B via =operator \n" RES;
	// 	B = A;		// _arr in B already had NEW memory, allocated in default constructor
	// 				// therefore it must be set deleted and set to NULL in the =overload

	// 	std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
	// 	std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";

	// 	std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
	// 	std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";

	// 	std::cout << BLU"    Change values in the array A\n" RES;
	// 	A[0] = 77;
	// 	A[1] = 88;
	// 	A[2] = 99;
	// 	std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
	// 	std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";




	// {
	// 	std::cout << MAG"Check if deep copy:   B(A);\n" RES;
	// 	std::cout << MAG"Duplicate object A to B using brackets:   Array <int> C(A) \n" RES;
	// 	Array <int> A(3);
	// 	A[0] = 11;
	// 	A[1] = 22;
	// 	A[2] = 33;
	// 	Array <int> B(A); // FOR B, ONLY COPY CONSTRUCTOR IS CALLED, SO IT NEVER GETS THE new MEMORY
	// 					  // THEREFORE YOU CANT DELETE THE B._arr, JUST MUST SET IT TO NULL	
	// 					  // B._arr IS SET TO NULL IN COPY CONSTR., SO IT COMES AS NULL INTO =overload
		
	// 	std::cout << "    A.size: " << A.size() << "\n    B.size: " << B.size() << "\n";
	// 	std::cout << "   &A: " << &A       << "\n   &B: " << &B << "\n\n";
		
	// 	std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
	// 	std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";

	// 	std::cout << BLU"    Change values in the array A\n" RES;
	// 	A[0] = 77;
	// 	A[1] = 88;
	// 	A[2] = 99;
	// 	std::cout << "    A[0] " << A[0] << ", A[1] " << A[1] << ", A[2] " << A[2] << "\n";
	// 	std::cout << "    B[0] " << B[0] << ", B[1] " << B[1] << ", B[2] " << B[2] << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		


	// {
	// 	std::cout << MAG"Check subscript overload\n" RES;
	// 	try
	// 	{
	// 		Array <int> A(3);
	// 		A[0] = 11;
	// 		std::cout << A[77] << "\n";
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << "Index is out of range!" << e.what() << '\n';
	// 	}
		
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
		


	// {
	// 	std::cout << MAG"Check Array with <string> arguments\n" RES;

	// 	Array <std::string> A(3);
	// 	A[0] = "wine";
	// 	A[1] = "beer";
	// 	A[2] = "cola";

	// 	std::cout << "Test subscript: \n";
	// 	std::cout << A[1] << "\n";
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";


		
	// {
	// 	std::cout << MAG"Testing   int* a = new int();\n" RES;
	// 	std::cout << MAG"Testing   int* b = new int[10];\n" RES;
	// 	int* a = new int();
	// 	int* b = new int[3]; // MAKING ARRAY b WITH 3 INTS
	// 	std::cout << "    *a: " << *a << "\n";
	// 	std::cout << "    *b: " << *b << "\n";
		
	// 	b[0] = 11;
	// 	b[1] = 22;
	// 	b[2] = 33;

	// 	std::cout << "     b[0]: " << b[0] << "\n";
	// 	std::cout << "     b[1]: " << b[1] << "\n";
	// 	std::cout << "     b[2]: " << b[2] << "\n";
		
	// 	std::cout << "    &b[0]: " << &b[0] << "\n";
	// 	std::cout << "    &b[1]: " << &b[1] << "\n";
	// 	std::cout << "    &b[2]: " << &b[2] << "\n";

	// 	delete a;
	// 	delete[] b;
	// } 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";
	


	// {
	// 	std::cout << MAG"Testing   Array object as a pointer\n" RES;

	// 	Array <int> *arrA = new Array<int>(3);
	// 	Array <int> *arrB = new Array<int>();

	// 	(*arrA)[0] = 2;
	// 	std::cout << "     (*arrA)[0]: " << (*arrA)[0] << "\n";

	// 	std::cout << "     arrA:       " << arrA << "\n";
	// 	std::cout << "     arrB:       " << arrB << "\n";

	// 	*arrB = *arrA;
	// 	delete arrA;
	// 	delete arrB;
	// } 	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";



	// {
	// 	std::cout << MAG"Testing more variants,  Array as a pointer\n" RES;

	// 	Array <int> *arrA = new Array<int>(3);
	// 	(*arrA)[0] = 11;
		
	// 	// Array <int> *arrB;						// calls default constructor
	// 	// Array <int> *arrB(arrA);					// copies just to the same address
	// 	Array <int> *arrB = new Array<int>(*arrA);	// creates a copy at new address and copies all values

	// 	std::cout << "     (*arrA)[0]: " << (*arrA)[0] << "\n";
	// 	std::cout << "     (*arrB)[0]: " << (*arrB)[0] << "\n";

	// 	std::cout << "     arrA:       " << arrA << "\n";
	// 	std::cout << "     arrB:       " << arrB << "\n";

	// 	// arrB = new Array<int>();

	// 	// *arrB = *arrA;
	// 	delete arrA;
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";



	// {
	// 	std::cout << MAG"2) Testing more variants,  Array as a pointer\n" RES;

	// 	Array <int> *arrA = new Array<int>(3);
	// 	Array <int> *arrB = new Array<int>(10);
	// 	(*arrA)[0] = 11;
	// 	(*arrB)[0] = 66;
		
		
	// 	std::cout << "     (*arrA)[0]: " << (*arrA)[0] << "\n";
	// 	std::cout << "     (*arrB)[0]: " << (*arrB)[0] << "\n";
	// 	std::cout << "     arrA:       " << arrA << "\n";
	// 	std::cout << "     arrB:       " << arrB << "\n";

	// 	*arrB = *arrA;
	// 	std::cout << "     (*arrA)[0]: " << (*arrA)[0] << "\n";
	// 	std::cout << "     (*arrB)[0]: " << (*arrB)[0] << "\n";
	// 	std::cout << "     arrA:       " << arrA << "\n";
	// 	std::cout << "     arrB:       " << arrB << "\n";

	// 	// *arrB = *arrA;
	// 	delete arrA;
	// 	delete arrB;
	// }	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - \n\n";





	//system ("leaks a.out");
    return 0;
}
