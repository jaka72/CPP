#include<iostream>
using namespace std;
 
class Complex
{
	private:
		int real, imag;

	public:
		Complex(int r = 0, int i = 0)
		{
			real = r;
			imag = i;
		}
		
		// This is automatically called when '+' is used
		// between two Complex objects
		Complex operator + (Complex const &obj)
		{
			Complex res;
			res.real = real + obj.real;
			res.imag = imag + obj.imag;
			return res;
		}
		
		void print()
		{
			cout << "real: " <<  real << ",   imag: " << imag << '\n';
		}
};
 
// THIS IS OPERATOR OVERLOAD
//		IT ADDS THE SAME MEMBERS OF 2 SEPARATE OBJECTS/CLASSES
// Complex operator + (Complex const &obj)
// {
// 	Complex res;
// 	res.real = real + obj.real;
// 	res.imag = imag + obj.imag;
// 	return res;
// }

int main()
{
    Complex c1(1, 2);
	Complex c2(10, 100);

    Complex c3 = c1 + c2;
    c3.print();
}