#include <iostream>
 
using namespace std;

double length = 0;

class Box 
{
   public:
      // Constructor definition
      Box(double l = 2.0, double b = 2.0, double h = 2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         height = h;
      }

      double Volume() 
      {
        cout << length << "\n";
        cout << this->length << "\n";
         return length * this->length;
      }

      int compare(Box box)
      {
        //return this->Volume() > box.Volume();
        return Volume();
      }
      
     double length;     // Length of a box

   private:
      double height;     // Height of a box
};


int main(void) 
{
   Box Box2(11, 22);    // Declare box1
   Box Box1(77, 88);    // Declare box2

   if (Box1.compare(Box2)) 
   {
      cout << "Box2 is smaller than Box1" <<endl;
   } else 
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   
   return 0;
}
