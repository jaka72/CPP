#include <iostream>
using namespace std;

class Engine final
{
	private:
		int horses = 0;
	
	public:
		// Engine () = default;
		Engine() : horses(33) {cout<<"Called constructor Engine\n";}
		// int gethorses() {return horses; }
		int gethorses() {return horses; }
};

// Class Car has a private member, which is 
//	an object of class Box 
class Car final
{
	private:
		// Engine *en1 = new Engine();
		// Engine  en2(Engine);
		//Engine  en2();  	// CONSTR NOT CALLED	???
		Engine  en3;		// CONSTR CALLED		???
		string name = "Ford";

	public:
		Car () { };
		// ~Car () { delete en1; }
		void getName()
		{
			//cout << "   Horses: " << en1->gethorses() <<"\n";
			cout << "   Name: " << name <<"\n";
			
		}
};

int main()
{
	//Engine a;
	// cout<<"   horses: "<< a.gethorses() << "\n";

	Car car1;
	// cout<<"   horses: "<< car1.gethorses() << "\n";
	// cout<<"   Name: "<< car1.getName() << "\n";
	// cout<<"   Name: "<< car1.getName() << "\n";
//	car1.getName();

	car1.en3.gethorses();

	return (0);
}
