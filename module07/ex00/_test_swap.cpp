#include <iostream>

//using namespace std;


class Animal
{
    private:

    public:
        int _a;
        int _b;

    Animal (int a, int b) : _a(a), _b(b)
    { } 
};


void swap(Animal &animal)
{
    std::cout << "My swap Animal\n";
    int temp;
    temp = animal._a;
    animal._a = animal._b;
    animal._b = temp;
}


void swap(int a, int b)
{
    std::cout << "My swap\n";
}


int main()
{
    int a = 3, b = 7;

    swap(a, b);
    std::cout << "a " << a << ",  b " << b << "\n";

    ::swap(a, b);
    std::cout << "a " << a << ",  b " << b << "\n";

    std::swap(a, b);
    std::cout << "a " << a << ",  b " << b << "\n";


    Animal cat(44, 88);
    std::cout << "cat.a " <<cat._a << ",  cat.b " << cat._b << "\n";
    swap(cat);
    std::cout << "cat.a " <<cat._a << ",  cat.b " << cat._b << "\n";


}