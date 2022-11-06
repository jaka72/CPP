#include <iostream>
#include <cmath> // for sqrt() function


class testOperator
{
    public:
        int data[100];

        // Default constr.
        testOperator() {};

        // Param. constr.
        testOperator(int a, int b, int c)
        {
            data[0] = a;
            data[1] = b;
            data[2] = c;
        }
    
        // Overload for operator[]              // WHEN [] USED WITH OBJECT cats:  cats[2]
        int& operator[](const int index)        // IT RETURNS THE VALUE FROM THE ARRAY    
        {
            std::cout << "Start overload[], index " << index << "\n ";

            if (index < 0)
                throw index;
        
            std::cout << "End overload[]\n ";

            return data[index];
        }
};



int main()
{
    std::cout << "Start Main\n ";
    int index = -1;

    testOperator a1(11, 22, 33);
    // a1.data[0] = 99;

    try
    {
        // OBJECT IS NOW ACTING AS AN ARRAY, WHEN USED WITH []
        // THIS a1[xz] ALWAYS TRIGGERS THE []OVERLOAD
        // CODE, CHECKS FOR BAD INDEX
        
        // std::cout << "data[0]: " << a1.data[index] << '\n';
           std::cout << "data[index]: " << a1[index] << '\n';   
                                                                
    }

    catch (int i)
    {
        std::cout << "   Cought invalid index\n";
    }

    std::cout << "End main\n ";
    return 0;
}
