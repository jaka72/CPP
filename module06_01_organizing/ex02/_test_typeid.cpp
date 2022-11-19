#include <iostream>
#include <typeinfo>
 
using namespace std;
 
class A
{
    public:
        A() {};
        virtual ~A() {};
        void funA()
        {
            cout<<"funA"<<endl;
        }
        virtual void fun()
        {
            cout<<"A's fun"<<endl;
        }
};
 
class B: public A
{
    public:
        B() {};
        ~B() {};
        void funB()
        {
            cout<<"funB"<<endl;
        }
        void fun()
        {
            cout<<"B's fun"<<endl;
        }
    //  A &parent;           // not possible
    //  B *child1 = &parent; // not possible
        A  parent;           // ok, non-reference
        B child2();          // ok
};

struct jakas
{
    int a;
};

int main()
{
    {
        B objB;
        A obj;
        A &objA = objB;

        long int     intA = 123;
        float   floatA;
        long double  doubleA;
        string  stringA = "asdqwewr ert";
        
        cout<<typeid(obj).name()<<endl;
        cout<<typeid(objB).name()<<endl;
        cout<<typeid(objA).name()<<endl;
        cout<<typeid(intA).name()<<endl;
        cout<<typeid(floatA).name()<<endl;
        cout<<typeid(doubleA).name()<<endl;
        cout<<typeid(stringA).name()<<endl;
        cout<<typeid(jakas).name()<<endl;
    }



    {
        B child;
        A *parent1 = &child;    // type is P of A
/*OR*/  A &parent2 =  child;    // type is B 
    
        cout<<typeid(child).name()<<endl;      // type is B 
        cout<<typeid(parent1).name()<<endl;    // type is P of A
        cout<<typeid(parent2).name()<<endl;    // type is B 
    }

    cout<<"is objA==objB? " << ((typeid(objA)==typeid(objB))==0?"False":"True")<<endl;
    
    return 0;

}
