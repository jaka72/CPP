
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
 

class Address : virtual public Person
{
	private:
	public:
		string street = "default_street";
		Address() { cout << "Address deafult\n"; }
		Address(string street, int id) : Person(id)
		{
   			cout<<"  Address::Address(int) called, street: " << street << endl;
   		}
};
 

class Name : virtual public Person 
{
	private:
	public:
		string wholename = "default_name";
		Name() { cout << "Name deafult\n"; }
    	Name(string wholename, int id) : Person(id)
		{
        	cout<<"  Name::Name(int ) called, wholename: " << wholename << endl;
    	}
};
 

class TA : public Address, public Name
{
	private:
	public:
		TA() 
		{
        	cout<<"    TA::TA() default"<< endl;
		};
    	TA(int i, string wholenm, string stt) : Person(i), Address(stt, i), Name(wholenm, i)
		{
        	cout<<"    TA::TA(int) parameterized"<< endl;
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
    // TA ta1;
	// ta1.printInfo();

    TA ta2(333, "Joco Znidarsic", "Zeedijk");
	ta2.printInfo();
}