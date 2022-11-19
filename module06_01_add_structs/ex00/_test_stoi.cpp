#include <iostream>
#include <string>
  
using namespace std;
  
// Driver Code
int main()
{
    int n;
    string s1 = "1234";
    string s2 = "1234abcd";
    string s3 = "1234  abcd";
    string s7 = "  1234  abcd";
    string s4 = "abcd";        // no conversion
    string s5 = "abcd1234";    // no conversion
    string s6 = "abcd  1234";  // no conversion
  
    // calling stoi() passing string as parameter.
    try
    {
        n = stoi(s1);
        cout << n << "\n";
        n = stoi(s2);
        cout << n << "\n";
        n = stoi(s3);
        cout << n << "\n";
        n = stoi(s7);
        cout << n << "\n";
        // n = stoi(s4);
        // cout << n << "\n";
        // n = stoi(s5);
        // cout << n << "\n";
        // n = stoi(s6);
        // cout << n << "\n";
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
  
}
