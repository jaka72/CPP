#include <iostream>


int main()
{
    // float f = 2147483647.0f;
              // 2147483647
       float f1 = 2147483647.0f;
       float f2 = 2147483648.0f;
              

//    int i =  static_cast<int>(f);

//  float ==  2.14748e+09
//  int       2147480000


    std::cout << "float " << f2 - f1 << "\n";
//   std::cout << "int   " << i << "\n";
}