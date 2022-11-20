#include <iostream>
// #include <string>
  
//using namespace std;
  
// Driver Code
int main()
{
    int n;
    std::string s1 = "1234";
    std::string s2 = "1234abcd";
    std::string s3 = "1234  abcd";
    std::string s7 = "  1234  abcd";
    std::string s4 = "abcd";        // no conversion
    std::string s5 = "abcd1234";    // no conversion
    std::string s6 = "abcd  1234";  // no conversion
  
    // calling stoi() passing string as parameter.
    try
    {
        n = stoi(s1);
        std::cout << n << "\n";
        n = stoi(s2);
        std::cout << n << "\n";
        n = stoi(s3);
        std::cout << n << "\n";
        n = stoi(s7);
        std::cout << n << "\n";
        // n = stoi(s4);
        // std::cout << n << "\n";
        // n = stoi(s5);
        // std::cout << n << "\n";
        // n = stoi(s6);
        // std::cout << n << "\n";
    
    
    std::string s8 = "2147483648";  // no conversion
    n = stoi(s6);
    std::cout << "n: " << n << "\n";
    
    
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}
