#include<iostream>
using namespace std;

#include <stdio.h>
#include "colors.h"

/*
	POINTER CAN BE NON DYNAMICALLY ALLOCATED WITH new, BUT SIMPLY AS    int *x;
		  OR
		DYNAMICALLY:    int *x = new int;			(in this case needs delete, and also cannot be changed ???)



	If there is a pointer *int in private members, apparently it does not need any p = new *int in the constr.
	and also no free in the destructor ??? 




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
		string _name;
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

		void set(string name, int x, int y, int p);	
		// void set(int x, int y);	

};

///////////////////////////////////////////////////////////////////////////////////////////////


Box::Box()	// :	_ptr(new int)		// also OK
{
	cout<<"Default Constructor\n";

	_name = "d";
	_x = 1;
	_y = 1;
	_ptr = new int;
	*_ptr = 1;
	
}



// void Box::set(int x, int y, int *p)
void Box::set(string name, int x, int y, int p)
{
	 _name	= name;
	 _x		= x;
	 _y		= y;
	*_ptr	= p;

	cout<< GRN"set:  " << _name <<  ",   x: "<< _x <<", &x: "<< &_x<<",    y: "<< _y <<", &y: "<< &_y <<",    ptr: "<< *_ptr <<", ptr: "<< _ptr <<RES"\n";
}




void Box::show()
{
	cout<< BLU"show: " << _name <<  ",   x: "<< _x <<", &x: "<< &_x<<",    y: "<< _y <<", &y: "<< &_y <<",    ptr: "<< *_ptr <<", ptr: "<< _ptr <<RES"\n";
}


//copy constructor -> it is responsible for deep copy.
Box::Box(Box &copy)
{
	cout<<"Copy Constructor\n";
	*this = copy; 
}


Box &Box::operator= (const Box &copy)
{
	cout<<"Assignement operator Constructor Overload\n";
	if (this == &copy)
		return *this;

	_name = copy._name;
	_x = copy._x;
	_y = copy._y;

	//if (_ptr != NULL)	// WHEN IS THIS NEEDED ???
	//	delete _ptr;

	_ptr = new int;
	*_ptr = *(copy._ptr);
	return *this;
}


Box::~Box()
{
	cout << "Destructor\n";
	delete _ptr;		// causing invalid pointer or double free
}



int main()
{
	int x = 1;
	int y = 1;
	int p = 1;

	{
		cout << "OBJECT AS NON-POINTER\n";
	//	Box d1();	// error
		Box d1;
		d1.show();
		d1.set("A", x, y, p);
		d1.show();

		d1.set("A", 111, 222, 999);
		d1.show();
	}

	std::cout << "- - - - - - - - - - - - - - \n\n";

	{
		cout << "COPYING OBJECT (AS NON-POINTER)\n";
	//	Box d1();	// error
		Box d1;
		Box d2(d1);

		d1.show();
		d2.show();

		d1.set("A", 2, 2, 2);
		d2.set("B", 9, 9, 9);

		d1.show();
		d2.show();
	}
		std::cout << "- - - - - - - - - - - - - - \n\n";


	{	// OBJECT AS POINTER
		cout << "OBJECT AS POINTER\n";
		Box *d1 = new Box();
		d1->show();
		d1->set("A", x, y, p);
		d1->show();
	 	d1->set("A", 111, 222, 999);
	 	d1->show();
		delete d1;
	}
		std::cout << "- - - - - - - - - - - - - - \n\n";



	{
		cout << "COPYING OBJECT (AS POINTER)\n";
		Box *d1 = new Box();
		d1->show();
		d1->set("A", 1, 1, 1);
		d1->show();

		Box *d2 = new Box(*d1);
		cout << "(Here first line is from object B, but still showing A, because just copied from A)\n";
	 	d2->show();
	 	d2->set("B", 9, 9, 9);

	 	d1->show();
		d2->show();
		delete d1;
		delete d2;
	}
		std::cout << "- - - - - - - - - - - - - - \n\n";


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
	// std::cout << "- - - - - - - - - - - - - - \n\n";

	

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
