#include<iostream>
using namespace std;

/*
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
		//int *ptr = new int;	// <-- THIS PREVENTS THE ptr TO BE FREED VIA DESTRUCTOR !!!
	
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


Box::Box()	//:	_ptr(new int)
{
	cout<<"Default Constructor\n";
	_ptr = new int;
}



void Box::set(int x, int y, int p)
{
	_x = x;
	_y = y;
	_ptr = &p;
	cout<< "Set, address of p: " << p <<"\n";
	cout<<"x: "<< _x <<", &x: "<< &_x <<",     y: "<< _y <<", &y: "<< &_y <<",     p: "<< *_ptr <<", ptr: "<< _ptr <<"\n";

}


void Box::show()
{
	cout<<"x: "<< _x <<", &x: "<< &_x<<",     ptr: "<< *_ptr<<", ptr: "<< _ptr <<"\n";
}


//copy constructor -> it is responsible for deep copy.
Box::Box(Box &b)
{
	cout<<"Copy Constructor\n";
	_x = b._x;
//	ptr = new int;		// was missing, causing segfault
//	*ptr = *(b.ptr);
	// - OR - //
	//		THE ABOVE IS NOT NEEDED, IF THERE IS OVERLOAD= CONSTRUCTOR
	// 		BUT ONLY IF THERE IS NO POINTER MEMBERS !!!!!!!!!!!!
	//*this = b; 
}


Box &Box::operator= (const Box &b)
{
//	cout<<"Assignement operator Constructor Overload\n";
//	_x = b._x;

	//if (ptr != NULL)
	//	delete ptr;

	//ptr = new int;
	// *_ptr = *(b._ptr);
	return *this;
}


Box::~Box()
{
	cout<< "Destructor\n";
	delete _ptr;
}





int main()
{
	int x = 11;
	int y = 33;
	int *p = &y;

	// cout<< "Main address of y: " << &y <<"\n";
	cout<< "Main, address of p: " << p <<"\n";
	cout<< "Main, address of y: " << &y <<"\n";

	Box d1;
	//d1.set(x, y, *p);
	//d1.show();
	cout<<"\n";


	// THE COPIED OBJECT ALWAYS HAS A DIFFERENT ADDRES, NO MATTER WHICH COPY METHOD
	// cout<< "Main, addres of object d1: " << &d1 << "\n";
	// Box d2;
	// d2 = d1;
	// cout<< "Main, addres of object d2: " << &d2 << "\n";


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
}
