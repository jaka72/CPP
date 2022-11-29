

// #include <conio.h>
#include <iostream>
using namespace std;
  
// defining a class template
template <class T, class U>
class info 
{
    public:
        info(T a, U b) // constructor of type template
        {
            cout << "\n" << "a = " << a << " size of data in bytes: " << sizeof(a);
            cout << "\n" << "b = " << b << " size of data in bytes: " << sizeof(b);
            cout << "\n";
        }
};
  
// Main Function
int main()
{
    // clrscr();
  
    info<char, int> p('x', 33);      // passing character value by creating an objects
  
    info<int, std::string> q(22, "milk");        // passing integer value by creating an object
    
    info<float, double> r(2.25, 3.33);    // passing float value by creating an object
  
    return 0;
}