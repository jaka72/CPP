
#include <iostream>


int		&myfun(int &x)
{
	//x = 2 + x;
	//std::cout << "a: "<<x<<"\n";
	return (x);
}



int main()
{
	int x = 1;

	myfun(x);
	std::cout << "x: "<<x<<"\n";

	myfun(x) = 10;

	std::cout << "x: "<<x<<"\n";


	// IS THERE A DIFFERENCE?
	const int &y = 12; // legal C++
	const int  q = 33;


	std::cout << "y: "<<&y<<"\n";

	std::cout << "q: "<<&q<<"\n";


}