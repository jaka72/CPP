#include <iostream>
#include <string>
#include <string_view> // only in c17
#include <cassert>	// for assert


class ArrayException
{
	private:
		std::string m_error;

	public:
		ArrayException(std::string error) : m_error{ error }
		{ 	}

		const std::string& getError() const
		{ return m_error; }
};


class IntArray
{
	private:
		int m_data[3]{}; // assume array is length 3 for simplicity

	public:
		IntArray() {}

		int getLength() const
		{ return 3; }

		int& operator[](const int index)
		{
			if (index < 0)
				throw ArrayException{ "*** This is printed from within a custom class,"
									"when an error occurs: Index less than zero!" };
			if (index >= getLength())
				throw ArrayException{ "*** This is printed from within a custom class, "
									" when an error occurs: Index bigger than length!" };
			
			
			return m_data[index];
		}
};


int main()
{
	IntArray array;


	try
	{
		//int a1{ array[-3] };  // error throw, index below
		int a2{ array[444] }; // error throw, index bigger than length
	}

	catch (const ArrayException& exception)
	{
		std::cerr << "Cought error from class intArray: \n   " << exception.getError() << "\n";
	}
}
