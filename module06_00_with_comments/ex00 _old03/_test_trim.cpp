#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string TrimFunction(string str)
{
    const char* whiteSpaces = " tnrfvm \n\r\t\f\v";
    str.erase(str.find_last_not_of(whiteSpaces) + 1);
    //str.erase(0, str.find_first_not_of(typeOfWhitespaces));
    return str;
}



int main()
{
    string str = "t     I Love C++ Programming.   tmt  tt  ";
    
    str = TrimFunction(str);
    
    cout << "Trimmed: [" << str << "]\n";
}