#include <iostream>
#include <string>
#include <string_view>


// EXCEPTION CLASSES: USEFUL TO GIVE DIFFERENT MESSAGES ACCORDING TO THE ERROR

class class_Exception
{
    private:
        std::string _error;

    public:
        // class_Exception(std::string_view error)
        class_Exception(std::string error)
            : _error{ error }
        {  }

	    const std::string& getError() const
        { return _error; }
};

class IntArray
{
    private:
        int m_data[3]{}; // assume array is length 3 for simplicity

    public:
        IntArray() {}

        int arrayLength() const { return 3; }

        int& operator[] (const int index)
        {
            // THROW A CLASS
            if (index < 0)
                throw class_Exception{ "Invalid: negative index" }; // Creates object, stores msg

            if (index >= arrayLength())
                throw class_Exception{ "Invalid: too high index" }; // Creates object, stores msg

            return m_data[index];
        }

};

int main()
{
	IntArray array;

    // TEST 1
	try
	{
		int test1{ array[5] }; // invalid index
	}
	catch (const class_Exception& exception) // YOU CAN CATCH A CLASS AS ARG, WHEN A CLASS IS THROWN 
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n"; // print msg from class
	}
    
    // TEST 2
    try
	{
		int test2{ array[-5] }; // invalid index
	}
	catch (const class_Exception& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n"; // print msg from class
	}

}