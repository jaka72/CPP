// strings and c-strings
#include <iostream>
#include <cstring>
#include <string>

int main ()
{
  std::string str ("Please split this sentence into tokens");

  char * cstr = new char [str.length()+1];
  std::strcpy (cstr, str.c_str());

  // cstr now contains a c-string copy of str

    char *p = std::strtok (cstr," ");
  while (p!=0)
  {
    std::cout << p << '\n';
    p = std::strtok(NULL," ");
  }

  delete[] cstr;
  return 0;
}








// // CPP program to demonstrate
// // strcat
// #include <string>
// #include <cstring>
// #include <iostream>

// using namespace std;

// int main()
// {
//     // char dest[50] = "This is an";
//     // char src[50] = " example";

// 	std::string dest = "This is an";
//     std::string src = " example";
 
//     // strcat(dest, src);
//     std::strcat(dest.c_str(), src.c_str());
//     cout << dest << "\n";

//     return 0;
// }