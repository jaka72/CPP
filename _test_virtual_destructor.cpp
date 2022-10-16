// A program with virtual destructor
#include <iostream>
 
using namespace std;
 
class base {
  public:
    base()    
    { cout << "Constructing base\n"; }
    //virtual ~base()
    ~base()
    { cout << "Destructing base\n"; }    
};
 
class derived : public base {
  public:
    derived()    
    { cout << "Constructing derived\n"; }
    //virtual ~derived()
    ~derived()
    { cout << "Destructing derived\n"; }
};
 
int main()
{
  // derived *d = new derived(); 
  // base *b = d;
  // delete b;
  
  derived d1;
  
  return 0;
}