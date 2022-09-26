

#include <iostream>
 
using namespace std; 

class S
{
    public:
        int n;
        
        // S();    // constructor definition:
    
        // S(int);       // constructor declaration
    
        S() : n(7)    // constructor definition:
        {  
            cout << "default n: " << n << "\n";
        }          // ": n(7)" is the initializer list
                        // ": n(7) {}" is the function body
            
        S(int x) : n(x)  // constructor definition: ": n{x}" is the initializer list
        {
            cout << "default n: " << n << "\n";
        }
};





int main()
{
    S s;      // calls S::S()

    S s2(10); // calls S::S(int)
}
