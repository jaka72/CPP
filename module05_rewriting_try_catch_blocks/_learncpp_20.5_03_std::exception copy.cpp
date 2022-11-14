#include <cstddef> // for std::size_t
#include <exception> // for std::exception
#include <iostream>
#include <limits>
#include <string> // for this example

int main()
{
    std::cout << "Show size_t max():  " << std::numeric_limits<std::size_t> ::max() << '\n';

    ///////////////////////////////////////////////////////////////////////////
    // A)
        std::cout << "\n- - - CATCHING STD::EXCEPTION BASE AND DERIVED CLASSES  - - - - - - -\n";


    try
    {
        // Your code using standard library goes here
        // We'll trigger one of these exceptions intentionally for the sake of the example
        std::string str;

        // will trigger a std::length_error or allocation exception
        str.resize( std::numeric_limits<std::size_t> ::max()); 
    }


    // This handler will catch std::length_error (and any exceptions derived from it) here
    // If this is commented out, it will still catch below, in the base class std::exception
    catch (const std::length_error& exception)
    {
        std::cerr << "   Custom message for std::length_error" << '\n';
    }


    // This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        std::cerr << "   Standard exception found: " << exception.what() << '\n';
    }


    ///////////////////////////////////////////////////////////////////////////
    // B)  CUSTOMIZABLE MESSAGE WITH RUNTIME ERROR CLASS 
            std::cout << "\n- - - CUSTOMIZABLE MESSAGE WITH RUNTIME ERROR CLASS - - - - - - -\n";
    try
    {
        throw std::runtime_error("   Customizable message");
    }

    catch (const std::exception& exc)
    {
        std::cerr << "   From standard exception: " << exc.what() << "\n";
    }

    return 0;
}