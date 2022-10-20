#include<iostream>
using namespace std;

#include <stdio.h>
#include "colors.h"

// QUESTION: 
//		Why is the value of _ptr different that set in the constructor? But address is still the same ???
//		Because it goes out of scope
//	

/*
	POINTER CAN BE NON DYNAMICALLY ALLOCATED WITH new, BUT SIMPLY AS    int *x;
		  OR
		DYNAMICALLY:    int *x = new int;			(in this case needs delete, and also cannot be changed ???)



	If there is a pointer *int in private members, apparently it does not need any p = new *int in the constr.
	and also no free in the destructor ??? 


	Helping site to see assembly code
	https://godbolt.org/   ALSO TRY COMPILING WITH FLAGS: -O2   -Ofast  
		(it will give you garbage values, if you go out of scope and try to print _ptr)


	A PROBLEM WITH LATER INITIALISATION, like: Box d1;
												d1.set(11, 77);
												Box d4;
												d4 = d1;
	In this case, d4 gets 2 times allocated memory:
			- first in default constr.
			- second in the assignment overload.
	Then, it is freed once, in the destructor, but ..

	SO, IT SEEMS THAT IT WORKS PROPERLY IN THIS CASES:
		- ASSIGN= OVERLOAD ONLY COPIES THE VALUES		   (This can happen later, after initialization)
		- COPY CONSTR ALLOCATES NEW MEMORY ==> DEEP COPY   (This can only happen once, 
															when the object is first initiated like:
																Box b(a)    OR
																Box c = a
*/


class Box
{
	private:
		int _x;
		int _y;
		int *_ptr;				//     IT HAS TO BE INITIALIZED IN THE CONSTRUCTOR!
		//int *_ptr = new int;	// <-- THIS PREVENTS THE ptr TO BE FREED VIA DESTRUCTOR !!!
	
	public:
		Box();

		//copy constructor -> it is responsible for deep copy.
		Box(Box &b);

		Box &operator= (const Box &b);

		~Box();

		void show();

		void set(int x, int y);	

};

///////////////////////////////////////////////////////////////////////////////////////////////

// POINTER CERATED NON DYNAMICALLY, JUST int *x;
Box::Box()
{
	cout << "Default Constructor\n";
	_x = 11;
	_y = 22;
	_ptr = &_y;
}



void Box::set(int x, int y)
{
	 _x		= x;
	 _y		= y;

	// delete _ptr;
	// _ptr	= new int;

	cout << "\nset:  x: "<< _x <<", &x: "<< &_x <<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<"\n";

	cout << "Changing _ptr to _x, inside set()\n";
	_ptr	= &_x;

	cout << "\nset:  x: "<< _x <<", &x: "<< &_x <<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<"\n";
	show();

	cout << "Changing value of _ptr, which has address of private _x, inside set()\n";
	*_ptr = 9876;
	// int temp 	= 321;
	// _ptr		= &temp;

	cout << "\nset:  x: "<< _x <<", &x: "<< &_x <<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<"\n";
	show();

	cout << "Changing value of _ptr, inside set()\n";
	// _x   = 888;
	// *_ptr = 777;
	show();



	//delete _ptr; 

}



void Box::show()
{
	cout<< BLU"show: x: "<< _x <<", &x: "<< &_x<<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<RES"\n";
}



//copy constructor -> it is responsible for deep copy.
Box::Box(Box &b)
{
	cout<<"Copy Constructor\n";
//	_x = b._x;
//	_ptr = new int;		// was missing, causing segfault
//	*_ptr = *(b._ptr);
	// - OR - //
	//		THE ABOVE IS NOT NEEDED, IF THERE IS OVERLOAD= CONSTRUCTOR
	// 		BUT ONLY IF THERE IS NO POINTER MEMBERS !!!!!!!!!!!!
	*this = b; 
}


Box &Box::operator= (const Box &b)
{
	cout<<"Assignement operator Constructor Overload\n";
	_x = b._x;

	if (_ptr != NULL)
		delete _ptr;

	_ptr = new int;
	*_ptr = *(b._ptr);
	return *this;
}


Box::~Box()
{
	cout << "Destructor\n";
	//delete _ptr;		// causing invalid pointer or double free
}



int main()
{
	int x = 11;
	int y = 33;
	// int *p;
	// p = &y;

	// cout<< "Main address of y: " << &y <<"\n";
	// cout<< "Main, address of p: " << p <<"\n";
	cout<< "Main, address of y: " << &y <<"\n\n";

	{	// as non pointer
		Box d1;

		cout << "\n_ptr is preserved, because it has an address of a private member.\n";
		d1.show();	// VALUE OF _ptr IS DIFFERENT THAN SET IN THE CONSTRUCTOR ???


		d1.set(x, y);

		d1.show();


	}
	std::cout << "- - - - - - - - - - - - - - \n";

	// {	// as pointer
	// //	Box *d1 = new Box;		// also good
	// 	Box *d1 = new Box();
	// 	d1->set(x, y, p);
	// 	d1->show();
	// 	delete d1;
	// }
	// std::cout << "- - - - - - - - - - - - - - \n";


	// {	// as pointer
	// //	Box *d1 = new Box;		// also good
	// 	Box *d1 = new Box();
	// 	d1->set(x, y, p);
	// 	d1->show();

	// 	*p = 999;
	// 	d1->set(x, y, p);
	// 	d1->show();
	// 	delete d1;
	// }
	// std::cout << "- - - - - - - - - - - - - - \n";

	

	// THE COPIED OBJECT ALWAYS HAS A DIFFERENT ADDRES, NO MATTER WHICH COPY METHOD
	// cout<< "Main, addres of object d1: " << &d1 << "\n";
	// Box d2;
	// d2 = d1;
	// // cout<< "Main, addres of object d2: " << &d2 << "\n";
	// d2.show();


	// Box d2 = d1;	// VIA COPY CONSTRUCTOR
	// d2.show();		// If there are pointers, they must get allocated new memory
	// cout<<"\n";		// If there is no custom Copy Constr, then the compiler's default is used,
	// 				//   but then it will make a shallow copy (no new allocation). This will cause
	// 				//   double free, because both vars point to same address.
	// 				// If there are a custom Copy Constr AND a custom Assign= Overload, then the Copy Constr 
	// 				//   can be simplified to:    *this = b;
	



	// Box d3(d1);		// VIA COPY CONSTRUCTOR
	// d3.show();
	// cout<<"\n.............\n\n";


	// Box d4;
	// d4 = d1;		// VIA ASSIGNEMENT OVERLOAD !!!
	// d4.show();		// So, it needs the custom overload for operator=
	// cout<<"\n";		// If there are pointers, they must get allocated new memory,
	// 				// otherwise the copy will be shallow (point to same address)

	
	// //d4.delete_ptr();	// Does not help preventing the leak
	//system("leaks a.out");
}
