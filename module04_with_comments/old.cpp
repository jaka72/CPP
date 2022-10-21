// Example: define member function without argument within the class
 
#include<iostream>
using namespace std;
 
class Person
{
    string name_private;
   
    public:
        string name_public;

        void set_p()
        {
            name_private = "Josef_private";
            name_public = "Josef_public";
        }
   
        void display_base()
        {
            cout << "From parent, name_private: " << name_private << ",  name_public: " << name_public << "\n";
        }
};
 

// class Student: private Person
class Student: public Person
{
    string course;
     
    public:
    void set_s()
        {
            set_p();
            cout<<"\nEnter something:\n";
            course = "AAAAA";
        }
         
        void show()
        {
            cout << "From child: " << course <<endl;
            display_base();
//            cout << "From child, name_private: " << name_private << "\n";
            cout << "From child, name_public: "  << name_public  << "\n";
//            cout << "from parent:" << Person::name <<endl;        // not accessible
        }
};
 
int main()
{
    Student s;

    s.set_s();
    s.show();
    return 0;
}
