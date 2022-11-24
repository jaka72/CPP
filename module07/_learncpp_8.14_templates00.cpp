#include <iostream>

// A)
template <typename T>
T max(T x, T y)
{
    std::cout << "called max<int>(int, int)\n";
    return (x > y) ? x : y;
}

// int max(int x, int y)    // NOT NEEDED BECAUSE OF ABOVE TEMPLATE
// {
//     std::cout << "called max(int, int)\n";
//     return (x > y) ? x : y;
// }


// B) 
template <typename T>
int someFcn (T x, double y)  // T = template type,  y = normal type
{
    return 5;
}





int main()
{
    std::cout << max<int>(1, 2) << '\n'; // selects max<int>(int, int)
    std::cout << max<>(1, 2) << '\n';    // deduces max<int>(int, int) (non-template functions not considered)
    std::cout << max(1, 2) << '\n';      // calls function max(int, int)



    someFcn(1, 3.4);    // matches someFcn(int, double)
    someFcn(1, 3.4f);   // matches someFcn(int, double) -- the float is promoted to a double
    someFcn(1.2, 3.4);  // matches someFcn(double, double)
    someFcn(1.2f, 3.4); // matches someFcn(float, double)
    someFcn(1.2f, 3.4f);// matches someFcn(float, double) -- the float is promoted to a double



    return 0;
}
