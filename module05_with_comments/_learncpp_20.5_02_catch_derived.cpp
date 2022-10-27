#include <iostream>

class Base
{
    public:
        Base() {}
};

class Derived: public Base
{
    public:
        Derived() {}
};

int main()
{
    try
    {
        throw Base();
        // throw Derived();
    }

    catch (const Derived& derived)  // DERIVED MUST BE BEFORE BASE
    {
        std::cerr << "caught Derived\n";
    }
    
    catch (const Base& base)
    {
        std::cerr << "caught Base\n";
    }

    return 0;
}