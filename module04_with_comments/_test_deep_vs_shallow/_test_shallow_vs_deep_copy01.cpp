#include<iostream>
using namespace std;

#include <stdio.h>

#include "colors.h"

/*
	If there is a pointer *int in private members, apparently it does not need any p = new *int in the constr.
	and also no free in the destructor ??? 

	Such priver pointer int *_ptr can only get assigned a neew address of another private member int, other
	addresses will be lost, because out of scope.
	(A private pointer can only point to other private members.)

	If value of such pointer is changed, it will be lost ouside of scope, if it has an address of a variable
	whick is out of scope.

	int *x = new int POINTER
	Such pointer has to be deleted, therefore it cant hold any other address the its own. It would cause segfault


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

		void set(int x, int y, int p);	

};

///////////////////////////////////////////////////////////////////////////////////////////////


Box::Box()	// :	_ptr(new int)		// also OK
{
	cout<<"Default Constructor\n";
	int temp;
	temp = 444;

	 _ptr = new int;
	*_ptr = 777;		// OK
	*_ptr = temp;		// OK
//	 _ptr = NULL;		// Error
//	 _ptr = &temp;		// Error, segfault and is leaking
}



void Box::set(int x, int y, int p)
{
	 _x		= x;
	 _y		= y;
	*_ptr	= p;

	cout << "\nset:  x: "<< _x <<", &x: "<< &_x <<",    y: "<< _y <<", &y: "<< &_y <<",      p: "<< *_ptr <<", ptr: "<< _ptr <<"\n";
}


void Box::show()
{
	cout<< BLU"show: x: "<< _x <<", &x: "<< &_x<<",    y: "<< _y <<", &y: "<< &_y <<",    ptr: "<< *_ptr <<", ptr: "<< _ptr <<RES"\n";
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
	delete _ptr;		// causing invalid pointer or double free
}





int main()
{
	int x = 11;
	int y = 33;
	int p = 444;

	// cout<< "Main address of y: " << &y <<"\n";
	//cout<< "Main, address of p: " << p <<"\n";
	cout<< "Main, address of y: " << &y <<"\n\n";

	{	// as non pointer
	//	Box d1();	// error
		Box d1;
		d1.set(x, y, p);
		d1.show();
	}
	std::cout << "- - - - - - - - - - - - - - \n";

	{	// as pointer
	//	Box *d1 = new Box;		// also good
		Box *d1 = new Box();
		d1->set(x, y, p);
		d1->show();
		delete d1;
	}
	std::cout << "- - - - - - - - - - - - - - \n";


	{	// as pointer
	//	Box *d1 = new Box;		// also good
		Box *d1 = new Box();
		d1->set(x, y, p);
		d1->show();

		p = 999;
		d1->set(x, y, p);
		d1->show();
		delete d1;
	}
	std::cout << "- - - - - - - - - - - - - - \n";

	

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