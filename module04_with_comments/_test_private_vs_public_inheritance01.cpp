
#include<iostream>
using namespace std;

class Base
{
    // private:
    protected:
        int m_id;

    public:

        Base(int id = 111)  : m_id (id )
        {   }

        int getId() const { return m_id; }
};

class Derived: public Base
{
    private:
        double m_cost;

    public:

        Derived(int id, double cost = 0.0)  :  Base (id ), m_cost (cost)
        {    }

        double getCost() const 
        { 
             cout << "    --------- base ID: " << m_id << "\n";
             cout << "    --------- base ID: " << getId() << "\n";
            return m_cost;
        }
};

//////////////////////////////////////////////////////////////////


int main()
{
    Base base1 (333);
    Base base2;         // IF NO ARG, IT AUTOM. GIVES 111 FROM THE CUSTOM CONSTR.

    cout << "base1 ID: " << base1.getId() << "\n";
    cout << "base2 ID: " << base2.getId() << "\n";

    Derived derived ( 222 );
    cout << "derived ID: "   << derived.getId() << "\n";
    cout << "derived cost: " << derived.getCost() << "\n";

    return 0;
}
