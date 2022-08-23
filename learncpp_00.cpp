#include <iostream>


// this function now returns an integer value
int getValueFromUser()
{
 	std::cout << "Enter an integer: ";

	int input{};
	std::cin >> input;

	return input; // return the value the user entered back to the caller
}


int main()
{
	// initialize num with the return value of getValueFromUser()
    int num { getValueFromUser() };

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}
