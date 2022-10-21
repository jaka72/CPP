#include<iostream>
using namespace std;

#include <stdio.h>
#include "colors.h"

// QUESTION: 
// HOW TO COPY AN OBJECT, WHICH WAS INITIALIZED AS A POINTER: Box *b1 = new Box()
// 		IT NEVER CALLS THE COPY CONSTR OR THE OVERLOAD= ???
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
		Box(const Box &b);

		Box &operator= (const Box &b);

		~Box();

		void show();

		void set(int x, int y);	

};

///////////////////////////////////////////////////////////////////////////////////////////////

// POINTER CREATED DYNAMICALLY: new int
Box::Box() //: _ptr(new int)
{
	cout << "Default Constructor\n";
	_x = 11;
	_y = 22;

	_ptr = new int;
	*_ptr = 987;
	//_ptr = &_x;	// !!! error when deleting, because I give him the address of the _x
}



void Box::set(int x, int y)
{
	 _x		= x;
	 _y		= y;

	cout << "\nset:  x: "<< _x <<", &x: "<< &_x <<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<"\n";

	show();
}



void Box::show()
{
	cout<< BLU"show: x: "<< _x <<", &x: "<< &_x<<",    y: "<< _y <<", &y: "<< &_y <<",    *ptr: "<< *_ptr <<", ptr: "<< _ptr <<RES"\n";
}



//copy constructor -> it is responsible for deep copy.
Box::Box(const Box &b)
{
	cout<<"Copy Constructor\n";
	// _x = b._x;
	// _ptr = new int;		// was missing, causing segfault
	// *_ptr = *(b._ptr);
	// - OR - //
	// 		THE ABOVE IS NOT NEEDED, IF THERE IS OVERLOAD= CONSTRUCTOR
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
	delete _ptr;		// causing invalid pointer or double free, or segfault
}



int main()
{
	int x = 11;
	int y = 33;

	// {	// as non pointer
	// 	Box d1;

	// 	d1.set(x, y);
	// }
	// std::cout << "- - - - - - - - - - - - - - \n";

	// {	// as pointer
	// 	Box *d1 = new Box();
	// 	d1->set(x, y);
	// 	delete d1;
	// }

	std::cout << "- - - - - - - - - - - - - - \n";


	{	// as pointer + call copy constr. 
	//	Box *d1 = new Box;		// also good
		Box *d1 = new Box();
		d1->set(1, 2);

//		Box *d2 = new Box(d1);  // NOT GOOD, no such function
//		Box *d2 = new Box();  // OR Box *d2(d1)    ???
//		Box *d2(d1);			// error, double free,   copy constr never called
//		d2 = d1;			// error, double free


		// THESE ARE NOT CALLING THE COPY CONSTR
		//Box *d2 = d1;
		//d2->set(11, 22);
		// d2->show();		// OK
		//Box *d3(d1);
		//d3->set(111, 222);


		// Box d2(*d1);		// error, invalid pointer
		// Box d2 = *d1;	// error, invalid pointer


		delete d1;
		//delete d2;
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
