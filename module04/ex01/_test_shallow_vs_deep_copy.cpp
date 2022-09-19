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
		int num;
		//int *ptr = new int;	// <-- THIS PREVENTS THE ptr TO BE FREED VIA DESTRUCTOR !!!
		int *ptr;				//     IT HAS TO BE INITIALIZED IN THE CONSTRUCTOR!
	
	public:
		Box() {
		cout<<"Default Constructor\n";
		ptr = new int;
	}
	
	void set(int x, int z) {
		num = x;
		*ptr = z;
	}
	
	void show() {
		cout<<"num: "<<num<<", &num: "<<&num<<",     ptr: "<<*ptr<<", ptr: "<<ptr<<"\n";
	}
	
	//copy constructor -> it is responsible for deep copy.
	Box(Box &b) {
		cout<<"Copy Constructor\n";
		num = b.num;
		ptr = new int;		// was missing, causing segfault
		*ptr = *(b.ptr);
		// - OR - //
		//		THE ABOVE IS NOT NEEDED, IF THERE IS OVERLOAD= CONSTRUCTOR
		// 		BUT ONLY IF THERE IS NO POINTER MEMBERS !!!!!!!!!!!!
		//*this = b; 
	}

	Box &operator= (const Box &b)
	{
		cout<<"Assignement operator Constructor Overload\n";
		num = b.num;

		//if (ptr != NULL)
		//	delete ptr;


		//ptr = new int;
		*ptr = *(b.ptr);
		return *this;
	}
	
	~Box() {
		cout<<"Destructor\n";
		delete ptr;
	}

 };
 
int main()
{
	Box d1;
	d1.set(11, 77);
	d1.show();
	cout<<"\n";


	Box d2 = d1;	// VIA COPY CONSTRUCTOR
	d2.show();		// If there are pointers, they must get allocated new memory
	cout<<"\n";		// If there is no custom Copy Constr, then the compiler's default is used,
					//   but then it will make a shallow copy (no new allocation). This will cause
					//   double free, because both vars point to same address.
					// If there are a custom Copy Constr AND a custom Assign= Overload, then the Copy Constr 
					//   can be simplified to:    *this = b;
	



	Box d3(d1);		// VIA COPY CONSTRUCTOR
	d3.show();
	cout<<"\n.............\n\n";


	Box d4;
	d4 = d1;		// VIA ASSIGNEMENT OVERLOAD !!!
	d4.show();		// So, it needs the custom overload for operator=
	cout<<"\n";		// If there are pointers, they must get allocated new memory,
					// otherwise the copy will be shallow (point to same address)

	
	//d4.delete_ptr();	// Does not help preventing the leak
}
