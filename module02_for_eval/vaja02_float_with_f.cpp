#include <iostream>
#include <stdio.h>


int main()
{
	float a = 3.2;
	if ( a == 3.2 )	// THIS IS NO EQUAL, BECAUSE LITERAL 3.2 IS AUTOM. TAKEN AS DOUBLE
		std::cout << "a is equal to 3.2\n";
	else
		std::cout << "a is not equal to 3.2\n";

	float b = 3.2;
	if ( b == 3.2f )
		std::cout << "b is equal to 3.2f\n";
	else
		std::cout << "b is not equal to 3.2f\n";

	float 	x = 2.3;
	double 	y = 2.3;

	std::cout << x << "\n";
	std::cout << y << "\n";

	printf("float: %.17f\n", x);
	printf("double: %.17f\n", y);
}
