#include <iostream>
#include <stdio.h>

// using namespace std;

// SUBSTITUTE FOR THE REAL CLASS
std::string *arr;
int nr{2};

// void store_lines()
// {
    
//     for(int i = 0; i < nr; i++)
//     {
//         cout << i << ' ' << "Write a line: ";
//         getline(std::cin, arr[i]);
// 		//std::cin.clear();
// 		//std::cin.ignore(1000, '\n');
//     }
// }

void viewArray()
{
    for(int i = 0; i < nr; i++)
        std::cout << "   " << i << ' ' << arr[i] << std::endl;
}

int main()
{
	std::cout << "Enter number: ";
    std::cin >> nr;

	printf("Nr: %d\n", nr);
    
    arr = new std::string[nr];
    //store_lines();
    
	//std::cin.clear();
	std::cin.ignore(1000, '\n');
	//std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	


	std::cout << "Write lines:\n";
    // getline(std::cin, arr[0]);
    // getline(std::cin, arr[1]);
    for(int i = 0; i < nr; i++)
    {
        std::cout << i << ' ' << "Write a line: ";
        getline(std::cin, arr[i]);
    }


    std::cout << "The lines: \n";
    viewArray();
    
    return 0;
}

