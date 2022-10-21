// Example: define member function without argument within the class
 
#include<iostream>
using namespace std;
 
class Parent
{
    protected:
        int     common;
        string  name_private;
   
    public:
        string name_public;

        void setInParent()
        {
            cout<<"Set in parent\n";
            common       = 999;
            name_private = "Josef_private";
            name_public  = "Josef_public";
        }
   
        void display_parent()
        {
            cout << "From parent, name_private: " << name_private << ",  name_public: " << name_public << "\n";
        }
};
 

// class Student: private Person
class Child : public Parent
{
    private:
        //int     common;
        string  course;
     
    public:
        void setInChild()
        {
            course = "AAAAA";
            cout<<"  Set in child\n";
            setInParent();
        }
         
        void show()
        {
            cout << "   From child: " << course <<endl;
            display_parent();
            cout << "From child, name_private: " << name_private << "\n";  // NOT ACCESSIBLE
            cout << "   From child, commonm int: " << common << "\n";  // NOT ACCESSIBLE
            cout << "   From child, name_public: "  << name_public  << "\n";
        }
};
 
int main()
{
    Parent p1;
    p1.setInParent();
    p1.display_parent();

    Child c1;
    c1.setInChild();
    c1.show();
    c1.setInParent();

    // Child c;

    // c.setInChild();
    // c.show();

    // cout << "a) " << c.name_public << "\n";

    // Parent p1 = Child();
    // p1.setInParent();


    return 0;
}
