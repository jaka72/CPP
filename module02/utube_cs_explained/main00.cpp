#include <iostream>

// A COPY CONSTRUCTOR CREATES ANOTHER SEPARATE OBJECT OF THE SAME CLASS
// AND COPIES VALUES FROM ORIGINAL TO THE NEW OBJECTS
//	

// DESTRUCTOR IS ONLY USEFULE WHEN AN ARRAY ON HEAP HAS BEEN ALLOCATED
//	IN THIS CASE IT NEEDS TO BE FREED IN THE DESTRUCTOR

/* STRANGE THING: 		Book (const Book & orig) {
							std::cout << "Copy    constructor\n";
							this->size = orig.size;
						}
		orig IS CALLED BY REFERENCE &, BUT IT IS NOT A POINTER ???
			THEREFORE WITH A DOT:  this->size = orig.size;
*/

/*	IT IS WRONG TO COPY OBJECTS LIKE THIS:	Book a(5);
											Book b(7);
											a = b;
	UNLESS YOU CREATE/USE THE "COPY ASSIGNMENT OPERATOR OVERLOAD"
		This would be "Shallow copy", causes a leak in case there is an arr
		THe 2 objects are not independent anymore.
*/

class Book
{
	private:
		int *arr;
		int size;

	public:
		// CONSTRUCTOR
		Book (int size = 10)
		{
			std::cout << "Default constructor\n";
			this->size = size;
			this->arr = new int [size];
		}

		// COPY CONSTRUCTOR
		Book (const Book &orig)
		{
			std::cout << "Copy    constructor\n";
			this->size = orig.size;
			this->arr = new int [this->size];
			for (int i = 0; i < this->size; ++i)
			{
				// this->arr[i] = orig.arr[i];
				this->arr[5] = 77;
			}
		}

		~Book () 
		{
			delete [] this->arr;
		}

		
		void print()
		{
			std::cout << "Size: " << size << '\n';
			std::cout << "   arr[5]: " << arr[5] << '\n';
		}
};





int main()
{
    Book a;
    Book b (a); // or Book b = a;
	Book c = b;

	// WRONG:
		b = a;  // ONLY POSSIBLE WITH COPY ASSIGNMENT OPERATOR OVERLOAD



	a.print();
	b.print();
	c.print();

}
