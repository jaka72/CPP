#include <iostream>
#include <vector>
//using namespace std;


template <typename T>
void printIt(T& vec)
{
    // INSIDE TEMPLATE MUST HAVE KEYWORD typename
    typename std::vector<int>::iterator v = vec.begin();
    while( v != vec.end()) {
      std::cout << "c) value of v = " << *v << std::endl;
      v++;
   }
}



int main() {

   // create a vector to store int
   std::vector<int> vec; 
   int i;

   // display the original size of vec
   std::cout << "vector size = " << vec.size() << std::endl;

   // push 5 values into the vector
   for(i = 0; i < 5; i++) {
      vec.push_back(i);
   }

   // display extended size of vec
   std::cout << "extended vector size = " << vec.size() << std::endl;

   // access 5 values from the vector
   for(i = 0; i < 5; i++) {
      std::cout << "value of vec [" << i << "] = " << vec[i] << std::endl;
   }

   // use iterator to access the values: WITHOUT typename IF OUTSIDE TEMPLATE
              std::vector<int>::iterator v = vec.begin();
   //typename std::vector<int>::iterator v2 = vec.begin();
   
//    while( v != vec.end()) {
//       std::cout << "value of v = " << *v << std::endl;
//       v++;
//    }

    printIt(vec);

   return 0;
}