// #ifndef INTARRAY_H
// #define INTARRAY_H

#include <cassert> // for assert()
#include <iostream>

class IntArray
{
private:
		int _length{};
		int* _data{};

public:
		IntArray() = default;


		IntArray(int length) : _length{ length }
		{
				assert(length >= 0);
				if (length > 0)
					_data = new int[length]{};
		}

		~IntArray()
    { delete[] _data; }

		void erase()
    {
        delete[] _data;
        _data = nullptr;
        _length = 0;
    }

		int& operator[](int index)
    {
        assert(index >= 0 && index < _length);
        return _data[index];
    }

		int getLength() const { return _length; }

		int getMember(int i) const { return _data[i]; }



		// Reallocate resizes the array. Deletes all content. 
		// Any existing elements will be destroyed. 
		//	This function operates quickly.
		void reallocate(int newLength)
		{
				erase();	// First we delete any existing elements
				if (newLength <= 0)	// If our array is going to be empty now, return here
						return;
				_data = new int[newLength];	// Then we have to allocate new elements
				_length = newLength;
		}


		// If new size is smaller, the rest of elements will be lost
		void resize(int newLength)
		{
			if (newLength == _length)
					return;	// if the array is already the right length, we're done

			if (newLength <= 0)
			{
					erase();
					return;	// If we are resizing to an empty array, do that and return
			}

			// So newLength is at least 1 element.
			// Now allocate a new array.  Then copy elements from the existing array
			// to the new array. Then destroy the old array, and make _data
			// point to the new array.
			int* data{ new int[newLength] };	// First we have to allocate a new array

			// Figure out how many elements to copy from the existing
			// array to the new array. We want to copy as many elements as there are
			// in the smaller of the two arrays.
			if (_length > 0)
			{
					int elementsToCopy{ (newLength > _length) ? _length : newLength };

					for (int index{ 0 }; index < elementsToCopy; ++index)
							data[index] = _data[index];	// Now copy elements one by one
			}
			delete[] _data;	// Can delete the old array, not needed it any more

			// And use the new array instead!  Note that this simply makes _data point
			// to the same address as the new array we dynamically allocated.  Because
			// data was dynamically allocated, it won't be destroyed when it goes out of scope.
			_data = data;
			_length = newLength;
	}




	void insertBefore(int value, int index)
	{
			assert(index >= 0 && index <= _length);	// Sanity check our index value

			int* data{ new int[_length+1] };	// create a new array 1 element larger than the old array

			for (int before{ 0 }; before < index; ++before)	// Copy all of the elements up to the index
					data[before] = _data[before];

			data[index] = value;	// Insert our new element into the new array

			for (int after{ index }; after < _length; ++after)
					data[after+1] = _data[after];	// Copy all of the values after the inserted element

			delete[] _data;	// Finally, delete the old array, and use the new array instead
			_data = data;
			++_length;
	}


	void remove(int index)
	{
			assert(index >= 0 && index < _length);	// Sanity check our index value

			if (_length == 1)
			{										// If this is the last remaining element in the array,
					erase();				// set the array to empty and bail out
					return;
			}

			// First create a new array one element smaller than the old array
			int* data{ new int[_length - 1] };

			for (int before{ 0 }; before < index; ++before)
					data[before] = _data[before];	// Copy all of the elements up to the index

			for (int after{ index+1 }; after < _length; ++after)
					data[after-1] = _data[after];	// Copy all of the values after the removed element

			delete[] _data;	// Finally, delete the old array, and use the new array instead
			_data = data;
			--_length;
	}


		// A couple of additional functions just for convenience
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, _length); }


};

// #endif



int main()
{
	IntArray arr(5);

	for (int i{0}; i < arr.getLength(); ++i)
    arr[i] = i + 1;

	for (int i{0}; i < arr.getLength(); ++i)
        std::cout << arr[i] << ' ';
  std::cout << "\n";

	arr.resize(10);

	for (int i{0}; i < arr.getLength(); ++i)
    std::cout << arr[i] << ' ';
  std::cout << "\n";

	// arr.insertBefore(333, 1);
	arr.insertBefore(11, 10);
	arr.insertBefore(22, 2);
	arr.insertBefore(33, 10);

	for (int i{0}; i < arr.getLength(); ++i)
    std::cout << arr[i] << ' ';
  std::cout << "\n";

	arr.resize(3);

	for (int i{0}; i < arr.getLength(); ++i)
    std::cout << arr[i] << ' ';
  std::cout << "\n";





	//std::cout << arr.getLength() << "\n";
	//std::cout << arr.getMember(0) << "\n";

}