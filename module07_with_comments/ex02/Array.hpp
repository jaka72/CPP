/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 10:36:45 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/22 20:42:19 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

template <typename T>

class Array
{
	private:
		T               *_arr;
		unsigned int    _size;

	public:
	// Constructors
		Array() : _size(0)	// create array with 0 size. So size gets a value already now
		{
			std::cout << GRE"Default constructor Array: created empty array\n" RES;
			_arr = new T[0];
		};
		

		Array(unsigned int n)	: _size(n)
		{
			std::cout << GRE"Param constructor Array: created array (size " << n << ")\n" RES;
			_arr = new T[_size];
			
			_arr[0] = 11;	// temp, for testing
			_arr[1] = 22;	// temp, for testing
		};
		
		
		// Copy constructor - must be deep copy!
		Array(const Array &src)
		{
			std::cout << GRE"\nCopy constructor Array\n" RES;
			std::cout << GRE"   (THE COPY HAS NO new ALLOCATED MEMORY YET, SO YOU CANT DELETE IT HERE, JUST SET TO NULL)\n" RES;
			std::cout << GRN"       what is src._arr  at this point: "      << src._arr << "\n" RES;
			std::cout << GRN"       what is this->arr at this point:      " << this->_arr << "\n" RES;

            if (this->_arr == NULL)
			    std::cout << LRD"       this->_arr is NULL\n" RES;
            else
            {
                std::cout << LRD"       this->_arr is NOT NULL\n" RES;                
			    std::cout << BLU"       what is this->_arr[0] at this point:   " << src._arr[0] << "\n" RES;
			    std::cout << BLU"       what is src._arr[0] at this point:   " << src._arr[0] << "\n" RES;
            }
            
			//std::cout << BLU"       what is arr[0] at this point:   " << this->_arr[0] << " (random value or segfault ?)\n" RES;

			// here not needed checking if its the same???  -->  if (this == &src) ...
			// 		Apparently not, because this check is already in =overload, so it
			//		happens there.
						
			// THE COPY HAS NO new ALLOCATED MEMORY YET, SO YOU CANT DELETE IT HERE, JUST SET TO NULL
			// if (this->_arr != NULL)		// !!! THIS PREVENTS LEAKS WHEN A = B
			// {							// BUT NOW B(A) GIVES DOUBLE FREE
			// 	delete []_arr;
			// }		
					

			// setting _arr to NULL, because now it is garbage 	
			std::cout << GRE"     Setting this->_arr to NULL\n" RES;
			this->_arr = NULL;	// !!! THIS IS CRUCIAL, TO PREVENT LEAKS OR DOUBLE FREE

			*this = src;		//			WHEN A = B    or   B(A)		!!!
			// here above the =overload already happened, so the duplicate already has different addresses
			
			// NOW THE _arr HAS SAME COPIED VALUES, BUT AT DIFFERENT ADDRESSES: 
			// std::cout << BLU"       src[0] address: " <<   src._arr << "\n" RES;
			// std::cout << BLU"       src[0] address: " << this->_arr << "\n" RES;
			// std::cout << GRN"       src[0] value:   " <<   src._arr[0] << "\n" RES;
			// std::cout << GRN"       src[0] value:   " << this->_arr[0] << "\n" RES;
		}


         ~Array()
		{
			std::cout << GRE"Destructor\n" RES;
			//std::cout << "    arr[0]:  " << _arr[0] << "\n";

			if (_arr != NULL)	// ADDED FROM TBLASE, WHERE WOULD_arr BE SET TO NULL ??
				delete []_arr;
		}


		// Assignment operator= overload
		Array &operator= (const Array &src)
		{
			std::cout << GRE"Assignment operator= overload\n" RES;
			std::cout << GRN"        src address:    " << src._arr << "\n" RES;
			std::cout << GRN"       _arr address:    " << this->_arr << "\n" RES;
			if (this == &src)
				return (*this);

			if (this->_arr == NULL)	
				std::cout << LRD"       _arr IS NULL!\n" RES;
            else
			{
				std::cout << LRD"       _arr IS NOT NULL, NOW deleting []_arr\n" RES;
				delete []this->_arr;
			}		
			
			this->_size = src._size;

			// copy whole array
			this->_arr = new T[_size]; 	// THIS IS CAUSING LEAK IN CASE A = B . ,WHERE THEN DOES THE MEMORY FOR THE NEW ARRAY COME FROM ???
									//   BUT WITHOUT THIS IS CAUSING DOUBLE FREE IN B(A)     ???
			std::cout << GRN"       _arr new address: " << this->_arr << "\n" RES;

			if (this->_arr == NULL)
			{
				// WHY 2 DIFFERENT ERROR MESSAGE VARIANTS ?
				// NOT SURE IF GOOD TO EXIT? BECAUSE THE OBJECT MAY NOT DESTRUCT!
				perror("memory allocation for Array _arr failed\n");
				std::cerr << "memory allocation for Array _arr failed\n";
			}
			
			// NOT SURE, THIS WE DID SO IN THE ANIMAL-BRAIN, BUT BRAIN WAS A CLASS OBJECT THERE
			// *this->_arr = *src._arr; // ????? THIS DOES NOT MAKE ANY DIFFERENCE, STILL 1 LEAK!

			std::cerr << GRE"   Copying array:\n" RES;
			unsigned int i = 0;
			while (i < _size)
			{
				this->_arr[i] = src._arr[i];
				std::cout << GRE"       while arr[i] = " << this->_arr[i] << "\n" RES;
				i++; 
			}
			return (*this);
		}


		// // subscript operator[] overload, with catching exception when out of bounds
		// T &operator[] (unsigned int i)
		// {
		// 	try
		// 	{
		// 		if (i < 0 || i >= _size || _arr == NULL)  // WHEN IS THIS SET TO NULL ?
		// 		{
		// 			//std::cout << "   Error, index is out of range!\n";
		// 			throw "    Throw: Error, index is out of range! Value: ";
		// 		}
		// 	}
		// 	catch(const char* str)
		// 	{
		// 		std::cout << str;
		// 	}
		// 	catch(const std::exception& e) // Is this needed ???
		// 	{
		// 		std::cerr << e.what() << '\n';
		// 	}
		// 	return (_arr[i]);
		// }


				// subscript operator[] overload, with catching exception when out of bounds
		T &operator[] (unsigned int i)
		{
			if (i < 0 || i >= _size || _arr == NULL)  // WHEN IS THIS SET TO NULL ?
			{
				//std::cout << "   Error, index is out of range!\n";
				//throw "    Throw: Error, index is out of range! Value: ";
				throw Array<T>::ArrayException(); //"    Throw: Error, index is out of range! Value: ";
			}

			return (_arr[i]);
		}


		unsigned int size() const
		{
			return (this->_size);
		}



		// Exceptions

		class ArrayException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>

const char* Array<T>::ArrayException::what() const throw()
{
	return ("(Exception from Array)\n");
}





#endif
