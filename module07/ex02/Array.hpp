/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/12 10:36:45 by jmurovec      #+#    #+#                 */
/*   Updated: 2022/11/25 10:57:28 by jmurovec      ########   odam.nl         */
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
		Array() : _size(0)
		{
			std::cout << GRE"Default constructor Array: created empty array\n" RES;
			_arr = new T[0];
		};
		

		Array(unsigned int n) : _size(n)
		{
			std::cout << GRE"Param constructor Array: created array (size " << n << ")\n" RES;
			_arr = new T[_size];
		};
		
		
		// Copy constructor
		// The copy has no NEW allocated memory yet, so it cannot be deleted here, just must be set to NULL0
		Array(const Array &src)
		{
			std::cout << GRE"\nCopy constructor Array\n" RES;

            if (this->_arr == NULL)
			    ; //std::cout << LRD"   this->_arr is NULL\n" RES;
            else
			{
                //std::cout << LRD"   _arr is not NULL. Now setting _arr to NULL\n" RES; // here it is still garbage 	
				this->_arr = NULL;	// This is crucial, to prevent leaks or double free !!
			}
			
			*this = src;
			// here above the =overload already happened, so the duplicate already has different addresses
		}


		// Assignment operator= overload
		// If the member _array is not NULL, it has to be freed, then it can get new memory 
		Array &operator= (const Array &src)
		{
			std::cout << GRE"Assignment operator= overload\n" RES;
			if (this == &src)
				return (*this);

			if (this->_arr == NULL)	
				; //std::cout << LRD"   _arr is NULL. It can get new memory\n" RES;
            else
			{
				//std::cout << LRD"   _arr is not NULL. Now deleting _arr, before allocating new memory\n" RES;
				delete []this->_arr;
			}		
			
			this->_size = src._size;

			this->_arr = new T[src._size];		// Allocate memory to the new copy
			//std::cout << GRN"   _arr new address: " << this->_arr << "\n" RES;
			
			std::cerr << GRE"   Copying array ...\n" RES;
			size_t i = 0;
			while (i < _size)
			{
				this->_arr[i] = src._arr[i];
				//std::cout << GRE"       arr[i] = " << this->_arr[i] << "\n" RES;
				i++; 
			}
			return (*this);
		}

        ~Array()
		{
			std::cout << GRE"Destructor\n" RES;
			if (_arr != NULL)
				delete []_arr;
		}

		// subscript operator[] overload, with catching exception when out of bounds
		T &operator[] (unsigned int i)
		{
			if (i < 0 || i >= _size || _arr == NULL)
			{
				throw Array<T>::ArrayException();
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
