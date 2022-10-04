#include <iostream>

class test
{
	public:
		int a;

		void print() { std::cout << "Hello\n"; }

		void (*fpt)();

};

int foo()
{
	std::cout << "called foo\n";
    return 5;
}


int main()
{
    int (*fpt)() = &foo;	// fpt points to function foo
    fpt = &foo; 			// fpt now points to function goo


	int (*fpt2)();
	fpt2 = &foo;

	fpt();				// Old compilers dont work
	fpt2();

	(*fpt)();			// Also old compilers work
//	 *fpt();			// error




    return 0;
}
