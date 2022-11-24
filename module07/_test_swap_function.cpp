
#include <iostream>

using namespace std;

// template <typename T>

// void    swap2(T &a, T &b)
// {
//     if (a == b)
//         std::cout << "Compare:    a is equal to b.\n";
//     else
//         std::cout << "Compare:    a is NOT equal to b.\n";
// }


int main()
{
    string a = "wine";
    string b = "beer";
    // int a = 2, b = 3;
    swap(a, b);    // THIS FUNCTION IS ALREADY INCLUDED SOMEWHERE IN std::
                    // OR IN iostream ????, WORKS WITH ALL TYPES
                    // BUT IF YOU OVERRIDE IT WITH A TEMPLATE swap()
                    // IT WILL NOT USE THE TEMPLATE, WHEN YOU GIVE IT STRINGS
    std::cout << "a: " << a << "\n";
}