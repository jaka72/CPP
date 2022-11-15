#include <iostream>


void func( int x )
{
    char* pleak = new char[1024]; // might be lost => memory leak
    std::string s( "hello world" ); // will be properly destructed

    if ( x ) throw std::runtime_error( "boom" );

    std::cout << "If throw(), then it does not continue in this function!\n";

    delete [] pleak; // will only get here if x == 0. if x!=0, throw exception
}

int main()
{
    try
    {
        func( 5 );
    }
    catch ( const std::exception& e )
    {
        std::cout << "A)\n";
        // return 1;
    }

    std::cout << "End)\n";
    return 0;
}