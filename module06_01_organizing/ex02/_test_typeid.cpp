#include <iostream>
#include <typeinfo>
#include "colors.h"


using namespace std;
 
class Animal
{
	public:
		Animal() {};
		virtual ~Animal() {};
		void function_Animal()
		{
			cout<<"Called function Animal\n";
		}
		virtual void make_sound()
		{
			cout<< "Called make_sound in Animal";
		}
};


class Cat: public Animal
{
	public:
		Cat() {};
		~Cat() {};
		void function_Cat()
		{
			cout<<"Called function Cat\n";
		}
		void common_function()
		{
			cout<< "Called make_sound in Cat\n";
		}
	//  A &parent;           // not possible
	//  B *child1 = &parent; // not possible
		Animal parent;           // ok, non-reference
		Cat child2();          // ok
};


struct jakas
{
	int a;
};

int main()
{
	{
		Cat	objB;
		Animal	obj;
		Animal	&objA = objB;

		long int	intA = 123;
		float		floatA;
		long double	doubleA;
		string		stringA = "asdqwewr ert";
		
		cout << typeid(obj).name() <<endl;
		cout << typeid(objB).name() <<endl;
		cout << typeid(objA).name() <<endl;
		cout << typeid(intA).name() <<endl;
		cout << typeid(floatA).name() <<endl;
		cout << typeid(doubleA).name() <<endl;
		cout << typeid(stringA).name() <<endl;
		cout << typeid(jakas).name() <<endl;
	}



	{
		Cat child;
		Animal *parent1 = &child;    // type is P of A
/*OR*/  Animal &parent2 =  child;    // type is B 
	
		cout<<typeid(child).name()<<endl;      // type is B 
		cout<<typeid(parent1).name()<<endl;    // type is P of A
		cout<<typeid(parent2).name()<<endl;    // type is B 
	}

   // cout<<"is objA==objB? " << ((typeid(objA)==typeid(objB))==0?"False":"True")<<endl;
	

	{
		cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n\n" RES;
		cout << BLU"Print type ID of basic types  - - - - - - - - - - - - - - - - -\n\n" RES;

		char c = 'C';
		cout << "char c:     " << typeid(c).name() <<endl;

		string s = "abcd efg";
		cout << "string s:   " << typeid(s).name() <<endl;

		int x = 33;
		cout << "int x:      " << typeid(x).name() <<endl;

		float f = 123.456f;
		cout << "float f:    " << typeid(f).name() <<endl;

		double d = 789.987;
		cout << "double d:   " << typeid(d).name() <<endl;
	}


	{
		cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n" RES;
		cout << BLU"\nPrint type ID of objects: non-pointers  - - - - - - - - - -\n\n" RES;

		Animal	parent;
		Cat		cat;

		parent = cat;
//		cat = parent;	// not possible
	
		cout << "Animal	parent:  " << typeid(parent).name() <<endl;
		cout << "Cat	cat:     " << typeid(cat).name() <<endl;
	}


	{
		cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n" RES;
		cout << BLU"\nPrint type ID of objects: pointers  - - - - - - - - - -\n\n" RES;

		Animal	*parent_ptr;
		Cat		*cat_ptr;
	
		parent_ptr = cat_ptr;
//		cat_ptr = parent_ptr;	// not possible

		cout << "Animal *parent_ptr:  " << typeid(parent_ptr).name() <<endl;
		cout << "Cat    *cat_ptr:     " << typeid(cat_ptr).name() <<endl;
	}


	{
		cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n" RES;
		cout << BLU"\nPrint type ID of objects: pointer or referrence - - - - - -\n\n" RES;

		Cat		cat;
		Animal	*parent_ptr = &cat;    // type Animal
/*OR*/  Animal	&parent_ref =  cat;    // type is Cat

		cout<< typeid(cat).name()<<endl;		// type is Cat 
		cout<< typeid(parent_ptr).name()<<endl;	// type is Animal
		cout<< typeid(parent_ref).name()<<endl;	// type is Cat 
	}


	{
		cout << MAG"\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n" RES;
		cout << BLU"\nPrint type ID of objects: pointer or referrence - - - - - -\n\n" RES;

		Cat		*cat;
		Animal	*parent_ptr = cat;    // type Animal
//		Animal	&parent_ref = cat;    // NOT POSSIBLE TO ASSIGN POINTER TO A REFERRENCE


		cout<< typeid(cat).name()<<endl;		// type is Cat 
		cout<< typeid(parent_ptr).name()<<endl;	// type is Animal
//		cout<< typeid(parent_ref).name()<<endl;	// NOT POSSIBLE 
	}


	return 0;

}
