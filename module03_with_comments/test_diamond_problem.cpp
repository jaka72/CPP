
#include<iostream>

using namespace std;
class Person
{
	private:
	public:
		int id;
	    Person()  { cout << "Person Default called" << endl;   }
	    Person(int id) : id(111) { cout << "Person::Person(int) called" << endl;   }
};
 
/////////////////////////////////////////////////////////////////////////////////
class Address : virtual public Person
{
	private:
	public:
		string street;
		Address() : street("default_street") { cout << "Address deafult\n"; }
		Address(string street, int id) : Person(id)
		{
   			cout<<"  Address::Address(int) called, street: " << street << endl;
   		}
};
 

class Name : virtual public Person 
{
	private:
	public:
		string wholename;
		Name() : wholename("default_name") { cout << "Name deafult\n"; }
    	Name(string wholename, int id) : Person(id)
		{
        	cout<<"  Name::Name(int ) called, wholename: " << wholename << endl;
    	}
};
///////////////////////////////////////////////////////////////////////////////////
 

class ABC : public Address, public Name
{
	private:
	public:
		ABC() 
		{
        	cout<<"    ABC::ABC() default"<< endl;
		};
    	ABC(int i, string wholenm, string stt) : Person(i), Address(stt, i), Name(wholenm, i)
		{
        	cout<<"    ABC::ABC(int) parameterized\n"<< endl;
			wholename = wholenm;
			street = stt;
			id = i;
		}
		void printInfo()
		{
			cout << id << ", " << wholename << ", " << street << "\n";
		}
};
 

int main()
{
    // ABC ABC1;
	// ABC1.printInfo();

    ABC abc(333, "Mario M", "Zeedijk");
	abc.printInfo();
}

