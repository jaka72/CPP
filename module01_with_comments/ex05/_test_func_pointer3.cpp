#include <iostream>

using namespace std;

class AB 
{
   public:
	  int sub(int a, int b)
	  {
		 return a - b;
	  }

	  int div(int a, int b) 
	  {
		 return a / b;
	  }
};


int outside(int a, int b)
{
	return a - b;
}

//using function pointer
int res1(int m, int n, AB* obj, int(AB::*fp)(int, int))
{
   return (obj->*fp)(m, n);
}


//using function pointer
int res2(int m, int n, AB* obj, int(AB::*fp2)(int, int))
{
   return (obj->*fp2)(m, n);
}


int main() 
{
   AB ob;

   cout << "Subtraction is = " << res1(8, 5, &ob, &AB::sub) << endl;
   cout << "Division is    = " << res2(4, 2, &ob, &AB::div) << endl;

	int (*fpt)(int, int);
	fpt = &AB::sub;		// WHY IS THIS NOT POSSIBLE


	fpt = &outside;


   return 0;
}