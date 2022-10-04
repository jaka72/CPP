#include <iostream>

class Test
{
	public:

		void print() { std::cout << "Hello\n";  }

		void (Test::*fpt)();

		void calling()
		{
			fpt = &Test::print;
			(this->*(fpt))();
		}

};



int main()
{
	Test test;

//	test.fpt = &Test::print;

//	test.fpt();

	test.calling();

    return 0;
}
