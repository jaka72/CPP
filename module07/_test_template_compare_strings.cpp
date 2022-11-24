#include <iostream>


template <typename T>

void    minimum (T &a, T &b)
{
    if (a == b)
        std::cout << "They're both the same.\n";
    else
        std::cout << "Compare ==    a is NOT equal to b.\n";
}

int main()
{
    {
        std::string str1 = "wine";
        std::string str2 = "wine";

        minimum(str1, str2);
    }
return 0;
}