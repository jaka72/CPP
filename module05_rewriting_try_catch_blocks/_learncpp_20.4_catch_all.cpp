#include <iostream>
#include <cmath> // for sqrt() function

// A modular square root function
double catch_exceptions(double x)
{
    std::cout << "   Start mySrt\n ";
    // If the user entered a negative number, this is an error condition
    if (x == 1)
        throw "";
    if (x == 2)
        throw 2;
    if (x == 3)
        throw 0.3;


    std::cout << "   After: no exceptions found\n ";

    
    return std::sqrt(x);
}

// TRY x = 1, 2, 3   TO SEE 3 DIFFERENT EXCEPTIONS a), b), c)

int main()
{
    std::cout << "Start Main\n ";
    double x = 1;

    try
    {
        std::cout << "Check the number " << x << " is: \n" << catch_exceptions(x) << '\n';
    }

    catch (const char *msg)
    {
        std::cout << "   Exception a), thrown string\n";
    }
    catch (int b)
    {
        std::cout << "   Exception b), thrown integer\n";
    }
    catch ( ... )
    {
        std::cout << "   Exception c), thrown other, (...) catch-all \n";
    }

    std::cout << "End main\n ";
    return 0;
}