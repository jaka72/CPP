#include <iostream>
#include <string>

using namespace std;

class Exception
{
	public:
	
		Exception(const string& msg) : _msg(msg)
		{
			cout << "      Constructor param: private _msg copied form argument\n";
		}
		
		~Exception()
		{ }

		string getMessage() const
		{
			cout << "   ///Called public getMessage() from class Exception/// ";
			return(_msg);
		}
	
	private:
		string _msg;
};

void fff()
{
	cout << "   Call fff: Here it calls throw ( Exception )\n";
	throw( Exception("Mr. Sulu") );
}

int main() {

   try
   {
		cout << "Call Try\n";
    	fff();
   }
   
   catch(Exception& eee)
   {
		cout << "Call Catch: Here calls eee.getMessage()\n";
        cout << "You threw an exception: " << eee.getMessage() << "\n";
   }
}

